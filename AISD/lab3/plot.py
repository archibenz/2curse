import matplotlib.pyplot as plt

def read_times(fn):
    ns, ti, tr = [], [], []
    with open(fn) as f:
        for line in f:
            n,a,b = map(int, line.split())
            ns.append(n); ti.append(a); tr.append(b)
    return ns, ti, tr

def main():
    ns, fi, fr = read_times("factorial_times.txt")
    _, si, sr = read_times("sum_times.txt")
    fig, axs = plt.subplots(1,2, figsize=(10,4))
    axs[0].plot(ns, fi, '-o', label='iter'); axs[0].plot(ns, fr, '-s', label='rec')
    axs[0].set(title="Factorial", xlabel="n", ylabel="ns"); axs[0].legend()
    axs[1].plot(ns, si, '-o', label='iter'); axs[1].plot(ns, sr, '-s', label='rec')
    axs[1].set(title="Sum", xlabel="n", ylabel="ns"); axs[1].legend()
    plt.tight_layout()
    plt.show()

if __name__ == "__main__":
    main()