#include <iostream>  
#include <vector>
#include <random>
#include <stack>
#include <stdexcept>
#include <mutex>
#include <algorithm>
#include <thread>
#include <unordered_set>
#include <chrono>
#include <queue>
#include <unordered_map>
#include <fstream>  
#include <iomanip>
#include <cstdlib>  
namespace our  
{  
    enum Directions  
    {  
        Up    = 1 << 0,  // 0001  
        Down  = 1 << 1,  // 0010  
        Left  = 1 << 2,  // 0100  
        Right = 1 << 3   // 1000  
    };  
    class Thread_sync  
    {  
        public:  
        std::vector<size_t> identifier;  
        std::vector<bool> flag;
        std::vector<std::thread>* threads;
        std::mutex mtx; // Мьюингс для флага
        
        Thread_sync(std::vector<std::thread>* t_threads)
        {   
            threads = t_threads;
            for (size_t i = 1; i <= ( threads->size() ); ++i) 
            {  
                flag.emplace_back(false);  
                identifier.emplace_back(i);
            }  
        }  
        
        bool get_flag(size_t index) 
        {  
            mtx.lock(); 
            bool flag_value = flag[index-1]; 
            mtx.unlock();  
            return flag_value;
        }

        void setFlag(size_t index) 
        {  
            mtx.lock();
            flag[index-1] = true;
            mtx.unlock();
        }  
        void run()
        {

        }
    };  

    class cell  
    {  
        public: 
        unsigned char wall_direction_mask;
        int in_use;
        int x_cord,y_cord;

        cell() : wall_direction_mask(15), in_use(0), x_cord(0), y_cord(0) {} //Шмаска по дефолту (по факту уже не нужна хихиххихих)

        cell(unsigned char C_wall_direction_mask, int C_in_use, int C_x_cord, int C_y_cord)
        {
            wall_direction_mask =  C_wall_direction_mask;
            in_use = C_in_use;
            x_cord = C_x_cord;
            y_cord = C_y_cord; 
        }
    };  

    class Maze   
    {   public:
        std::vector<std::vector<cell>> cell_array;
        int length, width;
        std::pair<int, int> start_cell_cords; //  Начало 
        std::pair<int, int> end_cell_cords;    // Финиш

        // Конструктор для лабиринта (Собрал бы???)
        Maze(int i_length, int i_width) 
        {
            initialization(i_length, i_width); 
            start_cell_cords = get_random_start_point(); // Определяем стартовую точку 
            end_cell_cords = get_random_end_point(start_cell_cords); // Определяем конечную точку 
        }

        int initialization(int i_length, int i_width) 
        {
            if (i_length <= 0 || i_width <= 0) 
            {
                throw std::invalid_argument("Недопустимые размеры"); //АЛЕКС, ВЫ НЕПРИЕМЛИМЫЙ НИГГЕР
                return 0;
            }
            length = i_length;
            width = i_width;
            cell_array.resize(length, std::vector<cell>(width));// В начале все стены будут стоять, а алгоритм создания сам будет проходить и убирать стены по мере прохождения 
            for (int x = 0; x < length; ++x) 
            {
                for (int y = 0; y < width; ++y) 
                {
                    cell_array[x][y] = cell(15, false, x, y);
                }
            }
            return 1;
        }

        std::pair<int, int> get_random_start_point() 
        {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dist;
            dist = std::uniform_int_distribution<>(0, 3);
            int side = dist(gen);
            int x, y; 

            
            // Выбираем случайный индекс внутри выбранной сторон
            switch (side) 
            {
                case 0: // Верхняя сторона
                    x = 0;
                    dist = std::uniform_int_distribution<>(0, width - 1);
                    y = dist(gen);
                    break;
                case 1: // Нижняя сторона
                    x = length - 1;
                    dist = std::uniform_int_distribution<>(0, width - 1);
                    y = dist(gen);
                    break;
                case 2: // Левая сторона
                    y = 0;
                    dist = std::uniform_int_distribution<>(0, length - 1);
                    x = dist(gen);
                    break;
                case 3: // Правая сторона
                    y = width - 1;
                    dist = std::uniform_int_distribution<>(0, length - 1);
                    x = dist(gen);
                    break;
            }

            return std::make_pair(x, y);
        }

        std::pair<int, int> get_random_end_point(const std::pair<int, int>& start)   
        {  
            std::pair<int, int> end;  
            do 
            {  
                end = get_random_start_point();  
            } while (end == start); 
            return end;  
        }  

        bool isValid(int x, int y) 
        {
            return x >= 0 && x < length && y >= 0 && y < width;
        } 

        unsigned char get_available_neighbors(int x, int y)  
        {
            unsigned char available_directions = 0;

            // Побитовая проверка соседней ячейки сверху
            if (isValid(x - 1, y) && !cell_array[x - 1][y].in_use) 
            {
                available_directions |= Up;
            }

            // Побитовая проверка соседней ячейки снизу
            if (isValid(x + 1, y) && !cell_array[x + 1][y].in_use)
            {
                available_directions |= Down;
            }

            // Побитовая проверка соседней ячейки слева
            if (isValid(x, y - 1) && !cell_array[x][y - 1].in_use) 
            {
                available_directions |= Left;
            }

            // Побитовая проверка соседней ячейки справа
            if (isValid(x, y + 1) && !cell_array[x][y + 1].in_use)
            {
                available_directions |= Right;
            }

            return available_directions;
        }

        unsigned char choose_random_move_direction(unsigned char directions) 
        {
             if (directions == 0)
             {
               return 0;
             }
              std::vector<our::Directions> available_directions;
              if(directions & our::Up)
              {
                 available_directions.push_back(our::Up);
              }
              if(directions & our::Down)
              {
                 available_directions.push_back(our::Down);
              }
              if(directions & our::Left)
              {
                 available_directions.push_back(our::Left);
              }
              if(directions & our::Right)
              {
                 available_directions.push_back(our::Right);
              }
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dist(0, available_directions.size() - 1);

             return available_directions[dist(gen)];
        }

        std::pair<int, int> move(std::pair<int, int> position, unsigned char direction)
        {
            int x = position.first;
            int y = position.second;
            switch (direction) 
            {
                case our::Up:
                    return {x - 1, y};
                case our::Down:
                    return {x + 1, y};
                case our::Left:
                    return {x, y - 1};
                 case our::Right:
                    return {x, y + 1};
                default:
                    throw std::invalid_argument("Недопустимое направление движения.");
            }
        }

        //Нужно для изменения стенки в клетке, в которую идут (ибо соседняя стенка между двумя клетками дублируется в памяти разных клеток)
        Directions get_opposite_direction( unsigned char direction) 
        {
            switch (static_cast<Directions>(direction)) {
                case Up: return Down;
                case Down: return Up;
                case Left: return Right;
                case Right: return Left;
                default: throw std::invalid_argument("Недопустимое направление движения.");
            }
        }

        int generate_backtrack()  
        {  
            std::pair<int, int> current_cell_cords, next_cell_cords;  
            cell* current_cell; // Указатель на текущую ячейку
            cell* next_cell; // Указатель на следующую ячейку   
            unsigned char current_cell_directions;  
            unsigned char move_direction;  
            std::stack<cell*> cell_stack; /// Стек указателей на ячейки  

            // Помещаем указатель на стартовую ячейку в стек  
            cell_stack.push(&cell_array[start_cell_cords.first][start_cell_cords.second]);  
            cell_array[start_cell_cords.first][start_cell_cords.second].in_use = 1;  

            while (!cell_stack.empty())  
            {  
                current_cell = cell_stack.top();  
                current_cell_cords = std::make_pair(current_cell->x_cord, current_cell->y_cord);  
                current_cell_directions = get_available_neighbors(current_cell_cords.first, current_cell_cords.second);  

                if (current_cell_directions == 0)  
                {  
                    cell_stack.pop();  
                    continue;  
                }  
                else  
                {  
                    move_direction = choose_random_move_direction(current_cell_directions);  
                    current_cell->wall_direction_mask &= ~move_direction;  

                    next_cell_cords = move(current_cell_cords, move_direction);  
                    next_cell = &cell_array[next_cell_cords.first][next_cell_cords.second];  

                    next_cell->wall_direction_mask &= ~get_opposite_direction(move_direction);  
                    next_cell->in_use = 1;  

                    cell_stack.push(next_cell); // Добавляем указатель на следующую ячейку    
                }  
            }  

            return 1;  
        }

        // ------------------------------------------------------------------
        //  Optimised non‑perfect backtracking: создаёт n «петель» во время обхода,
        //  а не пост‑фактум. extra_loops — сколько дополнительных проходов нуженo.
        int generate_imperfect_backtrack(int extra_loops)
        {
            std::pair<int,int> cur,nxt;
            cell *curCell,*nxtCell;
            unsigned char moves,dir;
            std::stack<cell*> st;

            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_real_distribution<> prob(0.0,1.0);

            st.push(&cell_array[start_cell_cords.first][start_cell_cords.second]);
            cell_array[start_cell_cords.first][start_cell_cords.second].in_use = 1;

            while(!st.empty())
            {
                curCell = st.top();
                cur = {curCell->x_cord,curCell->y_cord};
                moves = get_available_neighbors(cur.first,cur.second);

                // нет непосещённых — шанс пробить стену к посещённой клетке
                if(moves == 0)
                {
                    if(extra_loops > 0)
                    {
                        unsigned char visited = 0;
                        int x = cur.first, y = cur.second;
                        if(isValid(x-1,y) && cell_array[x-1][y].in_use && (curCell->wall_direction_mask & Up))    visited |= Up;
                        if(isValid(x+1,y) && cell_array[x+1][y].in_use && (curCell->wall_direction_mask & Down))  visited |= Down;
                        if(isValid(x,y-1) && cell_array[x][y-1].in_use && (curCell->wall_direction_mask & Left))  visited |= Left;
                        if(isValid(x,y+1) && cell_array[x][y+1].in_use && (curCell->wall_direction_mask & Right)) visited |= Right;

                        if(visited && prob(gen) < 0.35)    // 35 % шанс
                        {
                            dir = choose_random_move_direction(visited);
                            curCell->wall_direction_mask &= ~dir;
                            nxt = move(cur,dir);
                            nxtCell = &cell_array[nxt.first][nxt.second];
                            nxtCell->wall_direction_mask &= ~get_opposite_direction(dir);
                            --extra_loops;
                        }
                    }
                    st.pop();
                    continue;
                }

                // обычный шаг
                dir = choose_random_move_direction(moves);
                curCell->wall_direction_mask &= ~dir;
                nxt = move(cur,dir);
                nxtCell = &cell_array[nxt.first][nxt.second];
                nxtCell->wall_direction_mask &= ~get_opposite_direction(dir);
                nxtCell->in_use = 1;
                st.push(nxtCell);
            }
            return 1;
        }

    };

     // крч создам наследуемый класс, в котором ячейки будут разбиваться на мьютексные секции-квадраты какого-то размера 
    class MazeSync : public Maze
    {
        public:
        int mutex_cell_size;
        std::vector<std::mutex> mutexes;

        //ЕСЛИ ТЫ ЭТО ЧИТАЕШЬ - ПОРЫЧИ 100 РАЗ НА ПСА
        MazeSync(int i_length, int i_width, int i_mutex_cell_size) : Maze(i_length, i_width), mutex_cell_size(i_mutex_cell_size)
        {
            initialize_mutexes();
        }

        int calculate_mutex_count()  
        {
            if (mutex_cell_size <= 0) 
            {
                throw std::invalid_argument("Ð Ð°Ð·Ð¼ÐµÑ€ ÑÑ‡ÐµÐ¹ÐºÐ¸ Ð¼ÑŒÑŽÑ‚ÐµÐºÑÐ° Ð´Ð¾Ð»Ð¶ÐµÐ½ Ð±Ñ‹Ñ‚ÑŒ Ð¿Ð¾Ð»Ð¾Ð¶Ð¸Ñ‚ÐµÐ»ÑŒÐ½Ñ‹Ð¼.");
            }
            int horizontal_mutex_count = std::ceil(static_cast<double>(length) / mutex_cell_size);
            int vertical_mutex_count = std::ceil(static_cast<double>(width) / mutex_cell_size);
            return horizontal_mutex_count * vertical_mutex_count;
        }

        void initialize_mutexes() 
        {
            int mutex_count = calculate_mutex_count();
            mutexes = std::vector<std::mutex>(mutex_count); // Создаем вектор нужного размера, иначе он прилично ошибок выдаст, если изменять уже инициализированный вектор (типа, мьютексы нельзя копировать или перемещаь)
        }

        int get_mutex_index(int x, int y)  
        {
            if (mutex_cell_size <= 0) 
            {
                throw std::invalid_argument("Размер ячейки мьютекса должен быть положительным.");
            }
            if (x < 0 || x >= length || y < 0 || y >= width)
            {
                throw std::out_of_range("Координаты выходят за границы лабиринта.");
            }
            int mutex_x = x / mutex_cell_size;
            int mutex_y = y / mutex_cell_size;
            int horizontal_mutex_count = std::ceil(static_cast<double>(length) / mutex_cell_size);
            return mutex_x + mutex_y * horizontal_mutex_count;
        }

        bool try_lock_cell(int x, int y,  std::unordered_set <int>& locked_mutexes)
        {
            int mutex_index = get_mutex_index(x, y);
            locked_mutexes.insert(mutex_index);
            return mutexes[mutex_index].try_lock();
        }

        void lock_mutex(int x, int y)
        {
            int mutex_index = get_mutex_index(x, y);
            mutexes[mutex_index].lock();
        }

        void unlock_mutex(int x, int y)
        {
            int mutex_index = get_mutex_index(x, y);
            mutexes[mutex_index].unlock();
        }
        bool try_lock_mutex_with_timeout(int x, int y,  std::unordered_set <int>& locked_mutexes) 
        {
            auto start_time = std::chrono::steady_clock::now();
            const std::chrono::milliseconds timeout(6); // Фиксированный тайм-аут 6 мс

            while (true) {
                if (try_lock_cell(x, y, locked_mutexes)) 
                {
                    return true; // Успешно захвачен мьютекс 
                }

                // Проверяем, истек ли тайм-аут
                auto current_time = std::chrono::steady_clock::now();
                if (std::chrono::duration_cast<std::chrono::milliseconds>(current_time - start_time) >= timeout) 
                {
                    return false; // Тайм-аут истек, не удалось захватить мьютекс
                }

                // Короткая пауза для предотвращения спин-лока
                std::this_thread::sleep_for(std::chrono::milliseconds(1));
            }
        }
        
        // По идее не нужный метод, но я оставлю, зря писал что ли))))
        bool is_too_close(const std::pair<int, int>& p1, const std::pair<int, int>& p2) 
        {
            return (std::abs(p1.first - p2.first) <= 1 && p1.second == p2.second) ||
                   (std::abs(p1.second - p2.second) <= 1 && p1.first == p2.first);
        }

        std::vector<std::pair<int, int>> generate_random_start_points(int num_points)
        {
            if (num_points <= 0) 
            {
                throw std::invalid_argument("Количество точек должно быть положительным.");
            }

           if(num_points > std::max(length,width)) // Я на бумажке худший случай генерации рассмотрел, по идее так должно быть 
            {
               throw std::runtime_error("Слишком много точек, в лабиринте такого размера нет столько места.");
            }

            std::vector<std::pair<int, int>> start_points;

            while (start_points.size() < num_points)
            {
               std::pair<int,int> new_point = get_random_start_point();
                bool too_close = false;

                for (const auto& point : start_points) 
                {
                    if (is_too_close(new_point, point)) 
                    {
                     too_close = true;
                       break;
                    }
                }

                if (!too_close)
                {
                    start_points.push_back(new_point);
                }
            }
        
          return start_points;
        }

        // По идее не нужный метод, но я оставлю, зря писал что ли))))
        void set_random_start_end_points(std::vector<std::pair<int,int>> points) //Создаем стартовые точки для потоков + рандомно выбираем из них одну стартовую и одну финишную 
        {
            if (points.size() < 2)
            {
              throw std::invalid_argument("Необходимы две стартовые точки.");
            }

            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dist(0, points.size() - 1);
            int start_index = dist(gen);
            int end_index;

            do 
            {
                end_index = dist(gen);
            } while (end_index == start_index);

            start_cell_cords = points[start_index];
            end_cell_cords = points[end_index];
        } 

        // Новый метод от нейронки, который генерирует по точке старта для потока в уникальном мьютекса (чтоб несколько потоков не спавнилось в одном мьютексе )
        void generate_and_set_random_start_end_points(std::vector<std::pair<int, int>>& extreme_points)
        {
            if (mutex_cell_size <= 0)
            {
                throw std::invalid_argument("Размер мьютексной ячейки должен быть положительным");
            }

            std::vector<int> unique_mutex_indices;
            int horizontal_mutex_count = std::ceil(static_cast<double>(length) / mutex_cell_size);
            int vertical_mutex_count = std::ceil(static_cast<double>(width) / mutex_cell_size);

            // Добавляем все уникальные мьютексы, которые находятся на краях лабиринта
            for (int y = 0; y < vertical_mutex_count; y++)
            {
                unique_mutex_indices.push_back(get_mutex_index(0, y * mutex_cell_size)); // Верхняя граница
                unique_mutex_indices.push_back(get_mutex_index(length - 1, y * mutex_cell_size)); // Нижняя граница
            }
            for (int x = 1; x < horizontal_mutex_count - 1; x++)
            {
                unique_mutex_indices.push_back(get_mutex_index(x * mutex_cell_size, 0)); // Левая граница
                unique_mutex_indices.push_back(get_mutex_index(x * mutex_cell_size, width - 1)); // Правая граница
            }

            // Удаляем дубликаты
            std::sort(unique_mutex_indices.begin(), unique_mutex_indices.end());
            unique_mutex_indices.erase(std::unique(unique_mutex_indices.begin(), unique_mutex_indices.end()), unique_mutex_indices.end());

            if (unique_mutex_indices.size() < 2)
            {
                throw std::runtime_error("Не хватает крайних ячеек.");
            }

            extreme_points.clear();
            for (int mutex_index : unique_mutex_indices)
            {
                // Получаем координаты начала мьютексной области
                int mutex_x = (mutex_index % horizontal_mutex_count) * mutex_cell_size;
                int mutex_y = (mutex_index / horizontal_mutex_count) * mutex_cell_size;

            
                // Выбираем крайнюю точку
                int start_x, start_y;

                if(mutex_y == 0) // Верхняя граница
                {
                    start_x = mutex_x;
                    start_y = mutex_y;
                } else if (mutex_y > 0 && mutex_y <(vertical_mutex_count-1) * mutex_cell_size) // левая или правая граница
                        {
                            if(mutex_x == 0)
                            {
                                start_x = mutex_x;
                                start_y = mutex_y;
                            }
                            else
                            {
                                start_x = mutex_x + mutex_cell_size - 1;
                                start_y = mutex_y;
                            }
                            
                        }
                else // нижняя граница
                    {
                        start_x = mutex_x;
                        start_y =  mutex_y + mutex_cell_size - 1;
                    }

                if (isValid(start_x, start_y))
                {
                    extreme_points.push_back({start_x, start_y});
                }
            }

            if (extreme_points.size() < 2)
            {
                throw std::invalid_argument("Необходимо минимум две точки для выбора стартовой и конечной.");
            }

            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> distrib(0, extreme_points.size() - 1);

            int startIndex = distrib(gen);
            int endIndex;

            do {
                endIndex = distrib(gen);
            } while (endIndex == startIndex);

            start_cell_cords = extreme_points[startIndex];
            end_cell_cords = extreme_points[endIndex];
        }

          // Проверяет идентификатор другой клетки
        unsigned char check_another_thread_identifier (size_t thread_identifier, size_t another_thread_identifier, Thread_sync& thread_sync_pointer, Directions direction ) 
        {
            switch (another_thread_identifier)
                    {
                        case 0: 
                           return direction;
                        default:
                            // П��оверяем флаги соединения потоков
                            if ( !(thread_sync_pointer.get_flag (thread_identifier)) || !(thread_sync_pointer.get_flag (another_thread_identifier)) )
                                {
                                    return direction;
                                } 
                                else
                                { 
                                    return 0;
                                }
                    }
        }

        unsigned char multithread_get_available_neighbors(
            int x, 
            int y, 
            size_t thread_identifier,
            Thread_sync& thread_sync_pointer, 
            std::unordered_set <int>& locked_mutexes // Добавляем набор уникальных идентификаторов мьютексов для дальнейшего освобождения всех
        )  
        {
            unsigned char available_directions = 0;
            int current_cell_mutex_index = get_mutex_index(x, y);
            int neighbour_cell_mutex_index;
            size_t neighbour_cell_thread_identifier;
            unsigned char failed_try_lock_mutex = 0;

           // Побитовая проверка соседней ячейки сверху
            if (isValid(x - 1, y))
            {
                neighbour_cell_mutex_index = get_mutex_index(x - 1, y); 
               // Проверка неуникальности идентификатора мьютекса (если он неуникальный, то этот мьютекс уже захвачен)  + смотрит, что еще не обрабатывал её
                if (!(locked_mutexes.find(neighbour_cell_mutex_index) == locked_mutexes.end()) && (cell_array[x - 1][y].in_use != thread_identifier)) 
                {
                    neighbour_cell_thread_identifier = cell_array[x - 1][y].in_use;
                    available_directions |= check_another_thread_identifier(thread_identifier,neighbour_cell_thread_identifier, thread_sync_pointer,Up);
                }
                else if ((locked_mutexes.find(neighbour_cell_mutex_index) == locked_mutexes.end()))
                {
                    if (try_lock_cell(x - 1, y, locked_mutexes)&& (cell_array[x-1][y].in_use != thread_identifier))
                    {
                        neighbour_cell_thread_identifier = cell_array[x - 1][y].in_use;
                        available_directions |= check_another_thread_identifier(thread_identifier,neighbour_cell_thread_identifier, thread_sync_pointer, Up);
                    }
                    else
                    {
                        failed_try_lock_mutex |= Up;
                    }
                }
            }

            // Побитовая проверка соседней ячейки снизу
            if (isValid(x + 1, y))
            {
                neighbour_cell_mutex_index = get_mutex_index(x + 1, y);
                 // Проверка неуникальности идентификатора мьютекса (если он неуникальный, то этот мьютекс уже захвачен)  + смотрит, что еще не обрабатывал её
                if (!(locked_mutexes.find(neighbour_cell_mutex_index) == locked_mutexes.end()) && (cell_array[x + 1][y].in_use != thread_identifier))
                {
                    neighbour_cell_thread_identifier = cell_array[x + 1][y].in_use;
                    available_directions |= check_another_thread_identifier(thread_identifier,neighbour_cell_thread_identifier, thread_sync_pointer,Down);
                }
                else if ((locked_mutexes.find(neighbour_cell_mutex_index) == locked_mutexes.end()))
                {
                    if (try_lock_cell(x + 1, y, locked_mutexes)&& (cell_array[x+1][y].in_use != thread_identifier))
                    {
                        neighbour_cell_thread_identifier = cell_array[x + 1][y].in_use;
                        available_directions |= check_another_thread_identifier(thread_identifier,neighbour_cell_thread_identifier, thread_sync_pointer, Down);
                    }
                    else
                    {
                        failed_try_lock_mutex |= Down;
                    }
                }
            }
                
            // Побитовая проверка соседней ячейки снизу
            if (isValid(x, y - 1))
            {
                neighbour_cell_mutex_index = get_mutex_index(x, y - 1);
                 // Проверка неуникальности идентификатора мьютекса (если он неуникальный, то этот мьютекс уже захвачен)  + смотрит, что еще не обрабатывал её
                if (!(locked_mutexes.find(neighbour_cell_mutex_index) == locked_mutexes.end()) && (cell_array[x][y-1].in_use != thread_identifier))
                {
                    neighbour_cell_thread_identifier = cell_array[x][y-1].in_use;
                    available_directions |= check_another_thread_identifier(thread_identifier,neighbour_cell_thread_identifier, thread_sync_pointer, Left);
                }
                else if ((locked_mutexes.find(neighbour_cell_mutex_index) == locked_mutexes.end()))
                {
                    if (try_lock_cell(x, y - 1, locked_mutexes)&& (cell_array[x][y-1].in_use != thread_identifier))
                    {
                        neighbour_cell_thread_identifier = cell_array[x][y-1].in_use;
                        available_directions |= check_another_thread_identifier(thread_identifier,neighbour_cell_thread_identifier, thread_sync_pointer, Left);
                    }
                    else
                    {
                        failed_try_lock_mutex |= Left;
                    }
                }
            }

            // Побитовая проверка соседней ячейки слева
            if (isValid(x, y + 1))
            {
                neighbour_cell_mutex_index = get_mutex_index(x, y + 1);
                // Проверка неуникальности идентификатора мьютекса (если он неуникальный, то этот мьютекс уже захвачен)  + смотрит, что еще не обрабатывал её
                if (!(locked_mutexes.find(neighbour_cell_mutex_index) == locked_mutexes.end()) && (cell_array[x][y+1].in_use != thread_identifier))
                {
                    neighbour_cell_thread_identifier = cell_array[x][y+1].in_use;
                    available_directions |= check_another_thread_identifier(thread_identifier,neighbour_cell_thread_identifier, thread_sync_pointer, Right);
                }
            else if ((locked_mutexes.find(neighbour_cell_mutex_index) == locked_mutexes.end()))
                {
                    if (try_lock_cell(x, y + 1, locked_mutexes)&& (cell_array[x][y+1].in_use != thread_identifier))
                    {
                        neighbour_cell_thread_identifier = cell_array[x][y+1].in_use;
                        available_directions |= check_another_thread_identifier(thread_identifier,neighbour_cell_thread_identifier, thread_sync_pointer, Right);
                    }
                    else
                    {
                        failed_try_lock_mutex |= Right;
                    }
                }
            }
            // Побитовая проверка соседней ячейки справа
            if (failed_try_lock_mutex == 0)
            {
                return available_directions;
            }

            if(failed_try_lock_mutex & Up)
            {
                neighbour_cell_mutex_index = get_mutex_index(x-1, y );
                // Проверка неуникальности идентификатора мьютекса (если он неуникальный, то этот мьютекс уже захвачен)  + смотрит, что еще не обрабатывал её
                if (!(locked_mutexes.find(neighbour_cell_mutex_index) == locked_mutexes.end()) && (cell_array[x-1][y].in_use != thread_identifier))
                {
                    neighbour_cell_thread_identifier = cell_array[x - 1][y].in_use;
                    available_directions |= check_another_thread_identifier(thread_identifier,neighbour_cell_thread_identifier, thread_sync_pointer,Up);
                }
                else
                {
                    if (try_lock_mutex_with_timeout (x-1, y, locked_mutexes)&& (cell_array[x-1][y].in_use != thread_identifier))
                    {
                    neighbour_cell_thread_identifier = cell_array[x - 1][y].in_use;
                    available_directions |= check_another_thread_identifier(thread_identifier,neighbour_cell_thread_identifier, thread_sync_pointer,Up);
                    }
                }

            }

          
            if(failed_try_lock_mutex & Down)
            {
                neighbour_cell_mutex_index = get_mutex_index(x+1, y );
                //Обработка неудачно взятых мьютексов,сидим ждем теперь самых проблемных
                if (!(locked_mutexes.find(neighbour_cell_mutex_index) == locked_mutexes.end()) && (cell_array[x+1][y].in_use != thread_identifier))
                {
                    neighbour_cell_thread_identifier = cell_array[x + 1][y].in_use;
                    available_directions |= check_another_thread_identifier(thread_identifier,neighbour_cell_thread_identifier, thread_sync_pointer,Down);
                }
                else
                {
                    if (try_lock_mutex_with_timeout (x+1, y, locked_mutexes)&& (cell_array[x+1][y].in_use != thread_identifier))
                    {
                    neighbour_cell_thread_identifier = cell_array[x + 1][y].in_use;
                    available_directions |= check_another_thread_identifier(thread_identifier,neighbour_cell_thread_identifier, thread_sync_pointer, Down);
                    }
                }

            }

            if(failed_try_lock_mutex & Left)
            {
                neighbour_cell_mutex_index = get_mutex_index(x, y-1 );
                 // Проверка неуникальности идентификатора мьютекса (если он неуникальный, то этот мьютекс уже захвачен)  + смотрит, что еще не обрабатывал её
                if (!(locked_mutexes.find(neighbour_cell_mutex_index) == locked_mutexes.end()) && (cell_array[x][y-1].in_use != thread_identifier))
                {
                    neighbour_cell_thread_identifier = cell_array[x][y-1].in_use;
                    available_directions |= check_another_thread_identifier(thread_identifier,neighbour_cell_thread_identifier, thread_sync_pointer, Left);
                }
                else
                {
                    if (try_lock_mutex_with_timeout (x, y-1, locked_mutexes)&& (cell_array[x][y-1].in_use != thread_identifier))
                    {
                    neighbour_cell_thread_identifier = cell_array[x][y-1].in_use;
                    available_directions |= check_another_thread_identifier(thread_identifier,neighbour_cell_thread_identifier, thread_sync_pointer, Left);
                    }
                }
            }

        
            if(failed_try_lock_mutex & Right)
            {
                neighbour_cell_mutex_index = get_mutex_index(x, y+1 );
                 // Проверка неуникальности идентификатора мьютекса (если он неуникальный, т�� этот мьютекс уже захвачен)  + смотрит, что еще не обрабатывал её
                if (!(locked_mutexes.find(neighbour_cell_mutex_index) == locked_mutexes.end()) && (cell_array[x][y+1].in_use != thread_identifier))
                {
                    neighbour_cell_thread_identifier = cell_array[x][y+1].in_use;
                    available_directions |= check_another_thread_identifier(thread_identifier,neighbour_cell_thread_identifier, thread_sync_pointer, Right);
                }
                else
                {
                    if (try_lock_mutex_with_timeout (x, y+1, locked_mutexes)&& (cell_array[x][y+1].in_use != thread_identifier))
                    {
                    neighbour_cell_thread_identifier = cell_array[x][y+1].in_use;
                    available_directions |= check_another_thread_identifier(thread_identifier,neighbour_cell_thread_identifier, thread_sync_pointer, Right);
                    }
                }
            }
            return available_directions;
        }

        //НЕОБХОДИМО ВЫПУСТИТЬ, БРАТААААААН
        void unlock_all_mutexes (std::unordered_set <int>& locked_mutexes)
        {
            for (int mutex_index : locked_mutexes)
            {
                mutexes[mutex_index].unlock();
            }
            locked_mutexes.clear(); // Очищаем набор после разблокировки
        }
        
        void generate_multithread_backtrack(std::pair<int, int> start_cell_cords, size_t thread_identifier, Thread_sync& thread_sync_pointer)
        {
            lock_mutex(start_cell_cords.first, start_cell_cords.second);
            std::pair<int, int> current_cell_cords, next_cell_cords;
            std::stack<cell*> cell_stack; // Стек указателей на ячейки  
            cell* current_cell;
            cell* next_cell;
            unsigned char current_cell_directions;  
            unsigned char move_direction; 
            size_t next_cell_thread_identifier;
            std::unordered_set <int> locked_mutexes; 
            cell_stack.push(&cell_array[start_cell_cords.first][start_cell_cords.second]);  
            cell_array[start_cell_cords.first][start_cell_cords.second].in_use = thread_identifier;
            unlock_mutex(start_cell_cords.first, start_cell_cords.second);
            while (!cell_stack.empty())
            {
                lock_mutex(current_cell_cords.first, current_cell_cords.second);
                locked_mutexes.insert(get_mutex_index(current_cell_cords.first, current_cell_cords.second));
                current_cell = cell_stack.top();
                current_cell_cords = std::make_pair(current_cell->x_cord, current_cell->y_cord);  
                current_cell_directions = multithread_get_available_neighbors(
                    current_cell_cords.first, 
                    current_cell_cords.second,
                    thread_identifier,
                    thread_sync_pointer,
                    locked_mutexes
                    );
                if (current_cell_directions == 0)  
                {  
                    cell_stack.pop();  
                    unlock_all_mutexes(locked_mutexes);
                    locked_mutexes.clear();
                    continue;  
                } 
                else
                { 
                move_direction = choose_random_move_direction(current_cell_directions);
                next_cell_cords = move(current_cell_cords, move_direction);  
                next_cell = &cell_array[next_cell_cords.first][next_cell_cords.second];
                next_cell_thread_identifier = next_cell->in_use; 
                 // Если идем на объединение с другим потоком, то поднимаем флаги задействованности потоков в общей нити 
                switch(next_cell_thread_identifier) 
                {
                    case 0:
                        current_cell->wall_direction_mask &= ~move_direction; 
                        next_cell->wall_direction_mask &= ~get_opposite_direction(move_direction); 
                        next_cell->in_use = thread_identifier;  
                        cell_stack.push(next_cell);  // Добавляем указатель на следующую ячейку  
                        unlock_all_mutexes(locked_mutexes);
                        locked_mutexes.clear();
                        break;

                    default:
                        thread_sync_pointer.setFlag(thread_identifier);
                        thread_sync_pointer.setFlag(next_cell_thread_identifier); 
                        current_cell->wall_direction_mask &= ~move_direction; 
                        next_cell->wall_direction_mask &= ~get_opposite_direction(move_direction);  
                        cell_stack.push(next_cell); // Добавляем указатель на следующую ячейку 
                        unlock_all_mutexes(locked_mutexes);
                        locked_mutexes.clear();

                }
                }
            }
        }
            
     
    };

    void test()  
    {  
        std::cout << "YES, I LOVE MY..." << std::endl;  // ЧТОООО?
    }

    std::vector<std::pair<int, int>> find_shortest_path(MazeSync& maze, std::pair<int, int> start, std::pair<int, int> end) {
        // Check if start and end points are valid
        if (!maze.isValid(start.first, start.second) || !maze.isValid(end.first, end.second)) {
            throw std::invalid_argument("Start or end point is outside the maze.");
        }

        // Distance matrix to store the distance from the start point
        std::vector<std::vector<int>> distance(maze.length, std::vector<int>(maze.width, -1));
        // Queue for BFS
        std::queue<std::pair<int, int>> queue;
        // Map to store the previous cell for path reconstruction
        std::unordered_map<int, std::unordered_map<int, std::pair<int, int>>> prev;

        // Initialize the start point
        distance[start.first][start.second] = 0;
        queue.push(start);

        // Directions: up, down, left, right
        int dx[] = { -1, 1, 0, 0 };
        int dy[] = { 0, 0, -1, 1 };

        // Perform BFS
        while (!queue.empty()) {
            auto current = queue.front();
            queue.pop();

            // If we reached the end point, stop
            if (current == end) {
                break;
            }

            // Check all four directions
            for (int i = 0; i < 4; ++i) {
                int nx = current.first + dx[i];
                int ny = current.second + dy[i];

                // Check if the neighbor is valid and not visited
                if (maze.isValid(nx, ny) && distance[nx][ny] == -1) {
                    // Check if there is no wall in this direction
                    bool can_move = false;
                    switch (i) {
                    case 0: can_move = !(maze.cell_array[current.first][current.second].wall_direction_mask & our::Up); break;    // Up
                    case 1: can_move = !(maze.cell_array[current.first][current.second].wall_direction_mask & our::Down); break;  // Down
                    case 2: can_move = !(maze.cell_array[current.first][current.second].wall_direction_mask & our::Left); break;  // Left
                    case 3: can_move = !(maze.cell_array[current.first][current.second].wall_direction_mask & our::Right); break; // Right
                    }

                    if (can_move) {
                        distance[nx][ny] = distance[current.first][current.second] + 1;
                        queue.push({ nx, ny });
                        prev[nx][ny] = current;
                    }
                }
            }
        }

        // Reconstruct the path
        std::vector<std::pair<int, int>> path;
        if (distance[end.first][end.second] != -1) {
            std::pair<int, int> current = end;
            while (current != start) {
                path.push_back(current);
                current = prev[current.first][current.second];
            }
            path.push_back(start);
            std::reverse(path.begin(), path.end());
        }

        return path;
    }
         
    void print_maze(const Maze& maze) {
        for (int x = 0; x < maze.length; ++x) {
            // Top walls
            for (int y = 0; y < maze.width; ++y) {
                std::cout << "+";
                if (maze.cell_array[x][y].wall_direction_mask & our::Up) {
                    std::cout << "---";
                }
                else {
                    std::cout << "   ";
                }
            }
            std::cout << "+" << std::endl;

            // Side walls and cell content
            for (int y = 0; y < maze.width; ++y) {
                if (maze.cell_array[x][y].wall_direction_mask & our::Left) {
                    std::cout << "|";
                }
                else {
                    std::cout << " ";
                }

                // Start, end, or empty cell
                if (x == maze.start_cell_cords.first && y == maze.start_cell_cords.second) {
                    std::cout << " S "; // Start
                }
                else if (x == maze.end_cell_cords.first && y == maze.end_cell_cords.second) {
                    std::cout << " E "; // End
                }
                else {
                    std::cout << "   "; // Empty
                }
            }
            // Right wall
            std::cout << "|" << std::endl;
        }

        // Bottom walls
        for (int y = 0; y < maze.width; ++y) {
            std::cout << "+---";
        }
        std::cout << "+" << std::endl;
    }

    void print_maze_with_path(const MazeSync& maze, const std::vector<std::pair<int, int>>& path) {
        // Create a copy of the maze to mark the path
        std::vector<std::vector<char>> display(maze.length, std::vector<char>(maze.width, ' '));

        // Mark the path
        for (const auto& p : path) {
            display[p.first][p.second] = '*';
        }

        // Print the maze with the path
        for (int x = 0; x < maze.length; ++x) {
            // Top walls
            for (int y = 0; y < maze.width; ++y) {
                std::cout << "+";
                if (maze.cell_array[x][y].wall_direction_mask & our::Up) {
                    std::cout << "---";
                }
                else {
                    std::cout << "   ";
                }
            }
            std::cout << "+" << std::endl;

            // Side walls and cell content
            for (int y = 0; y < maze.width; ++y) {
                if (maze.cell_array[x][y].wall_direction_mask & our::Left) {
                    std::cout << "|";
                }
                else {
                    std::cout << " ";
                }

                // Start, end, path, or empty cell
                if (x == maze.start_cell_cords.first && y == maze.start_cell_cords.second) {
                    std::cout << " S "; // Start
                }
                else if (x == maze.end_cell_cords.first && y == maze.end_cell_cords.second) {
                    std::cout << " E "; // End
                }
                else if (display[x][y] == '*') {
                    std::cout << " * "; // Path
                }
                else {
                    std::cout << "   "; // Empty
                }
            }
            // Right wall
            std::cout << "|" << std::endl;
        }

        // Bottom walls
        for (int y = 0; y < maze.width; ++y) {
            std::cout << "+---";
        }
        std::cout << "+" << std::endl;
    }
    
    void print_path_coordinates(const std::vector<std::pair<int, int>>& path) {
        if (path.empty()) {
            std::cout << "Path not found!" << std::endl;
            return;
        }

        std::cout << "Path coordinates:" << std::endl;
        for (const auto& p : path) {
            std::cout << "(" << p.first << ", " << p.second << ") ";
        }
        std::cout << std::endl;
    }

    void print_maze_info(const MazeSync& maze) {
        std::cout << "Maze information:" << std::endl;
        std::cout << "Start: (" << maze.start_cell_cords.first << ", " << maze.start_cell_cords.second << ")" << std::endl;
        std::cout << "End: (" << maze.end_cell_cords.first << ", " << maze.end_cell_cords.second << ")" << std::endl;

        for (int x = 0; x < maze.length; ++x) {
            for (int y = 0; y < maze.width; ++y) {
                std::cout << "Cell [" << x << ", " << y << "]: "
                    << "walls = " << +maze.cell_array[x][y].wall_direction_mask
                    << ", in_use = " << maze.cell_array[x][y].in_use << std::endl;
            }
        }
    }
    //Исследование зависимости среднего времени генерации от размера мьютексных ячеек
    void test_multithread_generation_time
    (
        int length, 
        int width, 
        int test_variable_mutex_cell_size_min,
        int test_variable_mutex_cell_size_max,
        int num_tests,
        int num_threads
    )
    {
        std::ostringstream filename_stream; 
        filename_stream << "test_multithread_generation_times_" << num_threads << "threads.csv";
        std::ofstream csv_file(filename_stream.str());  
        if (!csv_file.is_open()) 
        {  
            throw std::invalid_argument("Ошибка с открытием файла.");
            return;  
        }  
        csv_file << "№" << "," << "размер мьютексной секции" <<","<< "время" <<"\n";
        for (
            int test_mutex_cell_size = test_variable_mutex_cell_size_min;  
            test_mutex_cell_size <= test_variable_mutex_cell_size_max;
            ++test_mutex_cell_size
            )
        {
            for (int test = 1; test <= num_tests; ++test) 
            {  
                MazeSync my_sync(length, width, test_mutex_cell_size); 
                std::vector<std::thread> threads(num_threads);  
                Thread_sync myStruct(&threads);  
                std::vector<std::pair<int, int>> start_points = my_sync.generate_random_start_points(num_threads);  
                my_sync.set_random_start_end_points(start_points);  

                // Точка начала отсчета 
                auto start_time = std::chrono::high_resolution_clock::now();  

                // генерация лабиринтуса 
                for (int i = 0; i < num_threads; ++i) 
                {  
                    threads[i] = std::thread(&MazeSync::generate_multithread_backtrack,  
                    &my_sync, start_points[i], i + 1, std::ref(myStruct));  
                }  
                for (auto& t : threads) {  
                    if (t.joinable()) 
                    {  
                        t.join();  
                    }  
                }  
                start_points.clear();

                auto end_time = std::chrono::high_resolution_clock::now();  
                std::chrono::duration<double, std::milli> duration = end_time - start_time;  
                // Записываем результат прогона
                csv_file << test << "," << test_mutex_cell_size<<"," <<std::fixed << std::setprecision(2) << duration.count() << "\n";  
            }  
        }

        csv_file.close();  
        std::cout <<filename_stream.str()<< std::endl; 
    }
    void test_generation_time_by_thread_num
    (
        int length, 
        int width, 
        int min_num_threads,
        int max_num_threads,
        int num_tests,
        int test_mutex_cell_size,
        bool want_one_thread
    )
    {
        std::ostringstream filename_stream; 
        filename_stream << "test_generation_time_by_thread_num_" << test_mutex_cell_size << "mutex_cell_size.csv";
        std::ofstream csv_file(filename_stream.str());  
        if (!csv_file.is_open()) 
        {  
            throw std::invalid_argument("Ошибка с открытием файла.");
            return;  
        }  

        csv_file << "№" << "," << "Количество потоков" <<","<< "время" <<"\n";
        switch (want_one_thread)
        {
        case 1:
            for (int test = 1; test <= num_tests; ++test) 
            {  
                Maze my(length, width);
                // Точка начала отсчета 
                auto start_time = std::chrono::high_resolution_clock::now();  
                my.generate_backtrack();
                auto end_time = std::chrono::high_resolution_clock::now();  
                std::chrono::duration<double, std::milli> duration = end_time - start_time;  
                // Записываем результат прогона
                csv_file << test << "," << "1"<<"," <<std::fixed << std::setprecision(2) << duration.count() << "\n";  
            }  
            break;
        
        default:
            break;
        }
        
        for (
            int num_threads = min_num_threads; 
            num_threads <= max_num_threads;
            ++ num_threads
            )
            {
            for (int test = 1; test <= num_tests; ++test) 
                {  
                    MazeSync my_sync(length, width, test_mutex_cell_size); 
                    std::vector<std::thread> threads(num_threads);
                    std::vector<std::pair<int, int>> start_points;  
                    Thread_sync myStruct(&threads);  
                    my_sync.generate_and_set_random_start_end_points(start_points) ;

                    // Точка начала отсчета 
                    auto start_time = std::chrono::high_resolution_clock::now();  

                    // генерация лабиринтуса 
                    for (int i = 0; i < num_threads; ++i) 
                    {  
                        threads[i] = std::thread(&MazeSync::generate_multithread_backtrack,  
                        &my_sync, start_points[i], i + 1, std::ref(myStruct));  
                    }  
                    for (auto& t : threads) {  
                        if (t.joinable()) 
                        {  
                            t.join();  
                        }  
                    }  

                    auto end_time = std::chrono::high_resolution_clock::now();  
                    std::chrono::duration<double, std::milli> duration = end_time - start_time;  
                    start_points.clear();
                    // Записываем результат прогона
                    csv_file << test << "," << num_threads<<"," <<std::fixed << std::setprecision(2) << duration.count() << "\n";  
                }  
            }

        csv_file.close();  
        std::cout <<filename_stream.str()<< std::endl; 
    }
    int get_optimal_thread_num(int length, int width, int mutex_cell_size)
    { 
        int optimal_thread_num = 2 *( std::ceil(static_cast<double>(length)/mutex_cell_size) + std::ceil(static_cast<double>(width)/mutex_cell_size)- 2);
        return optimal_thread_num;
    }

    // добавляем пункт 4
    void printMathDescriptions()
    {
        std::cout <<
        "1) Classic backtracking:\n"
        // Обновлён пункт 2:
        "2) Non‑perfect maze (optimised backtracking):\n"
        "   Modified DFS knocks down a wall to an already visited neighbour\n"
        "   while generating, until exactly n additional passages appear.\n"
        "   Time: O(W*H), Memory: O(W*H)\n\n"
        "3) Simple 20x20:\n"
        "   Random border openings без DFS.\n"
        "   Time: O(1)\n";
    }

    // добавляем пункт 5
    void calcArraySize()
    {
        int w,h;
        std::cout << "Введите ширину и высоту: ";
        if(!(std::cin>>w>>h)) return;
        long cells = (long)w * h;
        long bytes = cells * sizeof(our::cell) * 100;
        std::cout << "Для 100 лабиринтов потребуется " << bytes << " байт\n";
        std::cout << "Неидеальный алгоритм использует ту же память — структура клеток не меняется.\n";
    }

}

// Русское поле экспериментов
int main()
{
    using namespace std;
    while (true)
    {
        system("clear");
        cout <<
          "1. Классический 20×20\n"
          "2. «Неидеальный» 20×20 (1 вход + n выходов)\n"
          "3. Простой лабиринт (размер до 20×20)\n"
          "4. Математическое описание\n"
          "5. Расчёт для 100 лабиринтов\n"
          "0. Выход\n> ";
        int c; if(!(cin>>c)) { cin.clear(); cin.ignore(1e9,'\n'); continue; }
        system("clear");
        switch(c)
        {
          case 1:
          {
            // …генерация 20×20 backtrack…
            our::MazeSync m(20,20,1);
            m.generate_backtrack();
            // shortest path к единственному end_cell_cords
            auto path = our::find_shortest_path(m, m.start_cell_cords, m.end_cell_cords);
            our::print_path_coordinates(path);
            our::print_maze_with_path(m, path);
            break;
          }
          case 2:
{
    int n; 
    cout << "n выходов> "; 
    cin >> n;
    our::MazeSync m(20,20,1);
    // Заменено:
    m.generate_imperfect_backtrack(n);
    auto S = m.start_cell_cords;
    // сформировать n уникальных выходов
    vector<pair<int,int>> exits;
    while ((int)exits.size() < n) {
        auto e = m.get_random_start_point();
        if (e != S && find(exits.begin(), exits.end(), e) == exits.end())
            exits.push_back(e);
    }
    // режим вывода
    cout << "1. Ближайший выход\n2. Все выходы\nВыберите режим> ";
    int mode; cin >> mode;

    if (mode == 1) {
        // найти ближайший
        size_t best = 0, minD = SIZE_MAX;
        for (size_t i = 0; i < exits.size(); ++i) {
            auto p = our::find_shortest_path(m, S, exits[i]);
            if (!p.empty() && p.size() < minD) {
                minD = p.size();
                best = i;
            }
        }
        m.end_cell_cords = exits[best];
        auto p = our::find_shortest_path(m, S, m.end_cell_cords);
        our::print_path_coordinates(p);
        our::print_maze_with_path(m, p);
    }
    else {
        // вывести n лабиринтов
        for (size_t i = 0; i < exits.size(); ++i) {
            m.end_cell_cords = exits[i];
            auto p = our::find_shortest_path(m, S, m.end_cell_cords);
            cout << "\nВыход " << i+1 << " (" << exits[i].first << "," << exits[i].second << "):\n";
            our::print_path_coordinates(p);
            our::print_maze_with_path(m, p);
        }
    }
    break;
}

          case 3:
          {
            int W,H; cout<<"Ширина Высота (1..20)> "; cin>>W>>H;
            if(W<1||W>20||H<1||H>20){ cout<<"Неверный размер\n"; break; }
            our::MazeSync m(W,H,1);
            m.generate_backtrack();
            // shortest path к единственному end_cell_cords
            auto path = our::find_shortest_path(m, m.start_cell_cords, m.end_cell_cords);
            our::print_path_coordinates(path);
            our::print_maze_with_path(m, path);
            break;
          }
          case 4:
            our::printMathDescriptions();
            break;
          case 5:
            our::calcArraySize();
            break;
          case 0:
            return 0;
          default:
            cout << "Неверный ввод\n";
        }
        cout<<"\nНажмите Enter..."; cin.ignore(1e9,'\n'); cin.get();
    }
}