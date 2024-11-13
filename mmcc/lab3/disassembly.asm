
execfile.o:	file format mach-o arm64

Disassembly of section __TEXT,__text:

0000000000000000 <ltmp0>:
       0: d10083ff     	sub	sp, sp, #32
       4: a9017bfd     	stp	x29, x30, [sp, #16]
       8: 910043fd     	add	x29, sp, #16
       c: b81fc3a0     	stur	w0, [x29, #-4]
      10: b85fc3a8     	ldur	w8, [x29, #-4]
      14: 11000500     	add	w0, w8, #1
      18: 94000000     	bl	0x18 <ltmp0+0x18>
      1c: a9417bfd     	ldp	x29, x30, [sp, #16]
      20: 910083ff     	add	sp, sp, #32
      24: d65f03c0     	ret

0000000000000028 <__Z6tgammaB8ue170006IiENSt3__19enable_ifIXsr3std11is_integralIT_EE5valueEdE4typeES2_>:
      28: d10083ff     	sub	sp, sp, #32
      2c: a9017bfd     	stp	x29, x30, [sp, #16]
      30: 910043fd     	add	x29, sp, #16
      34: b81fc3a0     	stur	w0, [x29, #-4]
      38: bc5fc3a1     	ldur	s1, [x29, #-4]
      3c: 1e204020     	fmov	s0, s1
      40: 0f20a400     	sshll.2d	v0, v0, #0
      44: 5e61d800     	scvtf	d0, d0
      48: 94000000     	bl	0x48 <__Z6tgammaB8ue170006IiENSt3__19enable_ifIXsr3std11is_integralIT_EE5valueEdE4typeES2_+0x20>
      4c: a9417bfd     	ldp	x29, x30, [sp, #16]
      50: 910083ff     	add	sp, sp, #32
      54: d65f03c0     	ret

0000000000000058 <_main>:
      58: d101c3ff     	sub	sp, sp, #112
      5c: a9067bfd     	stp	x29, x30, [sp, #96]
      60: 910183fd     	add	x29, sp, #96
      64: 90000008     	adrp	x8, 0x0 <_main+0xc>
      68: f9400108     	ldr	x8, [x8]
      6c: f9000fe8     	str	x8, [sp, #24]
      70: 90000008     	adrp	x8, 0x0 <_main+0x18>
      74: f9400108     	ldr	x8, [x8]
      78: f90013e8     	str	x8, [sp, #32]
      7c: b81fc3bf     	stur	wzr, [x29, #-4]
      80: 14000001     	b	0x84 <_main+0x2c>
      84: f9400fe0     	ldr	x0, [sp, #24]
      88: 90000001     	adrp	x1, 0x0 <_main+0x30>
      8c: 91000021     	add	x1, x1, #0
      90: 94000000     	bl	0x90 <_main+0x38>
      94: f94013e0     	ldr	x0, [sp, #32]
      98: d10043a1     	sub	x1, x29, #16
      9c: 94000000     	bl	0x9c <_main+0x44>
      a0: f9400fe0     	ldr	x0, [sp, #24]
      a4: 90000001     	adrp	x1, 0x0 <_main+0x4c>
      a8: 91000021     	add	x1, x1, #0
      ac: 94000000     	bl	0xac <_main+0x54>
      b0: f94013e0     	ldr	x0, [sp, #32]
      b4: d10053a1     	sub	x1, x29, #20
      b8: 94000000     	bl	0xb8 <_main+0x60>
      bc: fc5f03a0     	ldur	d0, [x29, #-16]
      c0: b85ec3a0     	ldur	w0, [x29, #-20]
      c4: 94000000     	bl	0xc4 <_main+0x6c>
      c8: fd000be0     	str	d0, [sp, #16]
      cc: b85ec3a0     	ldur	w0, [x29, #-20]
      d0: 94000000     	bl	0xd0 <_main+0x78>
      d4: 1e604001     	fmov	d1, d0
      d8: fd400be0     	ldr	d0, [sp, #16]
      dc: 1e611800     	fdiv	d0, d0, d1
      e0: fc1e03a0     	stur	d0, [x29, #-32]
      e4: 2f00e400     	movi	d0, #0000000000000000
      e8: fc1d83a0     	stur	d0, [x29, #-40]
      ec: b81d43bf     	stur	wzr, [x29, #-44]
      f0: 14000001     	b	0xf4 <_main+0x9c>
      f4: b85d43a8     	ldur	w8, [x29, #-44]
      f8: b85ec3a9     	ldur	w9, [x29, #-20]
      fc: 6b090108     	subs	w8, w8, w9
     100: 1a9fd7e8     	cset	w8, gt
     104: 37000268     	tbnz	w8, #0, 0x150 <_main+0xf8>
     108: 14000001     	b	0x10c <_main+0xb4>
     10c: fc5f03a0     	ldur	d0, [x29, #-16]
     110: b85d43a0     	ldur	w0, [x29, #-44]
     114: 94000000     	bl	0x114 <_main+0xbc>
     118: fd0007e0     	str	d0, [sp, #8]
     11c: b85d43a0     	ldur	w0, [x29, #-44]
     120: 94000000     	bl	0x120 <_main+0xc8>
     124: 1e604001     	fmov	d1, d0
     128: fd4007e0     	ldr	d0, [sp, #8]
     12c: 1e611801     	fdiv	d1, d0, d1
     130: fc5d83a0     	ldur	d0, [x29, #-40]
     134: 1e612800     	fadd	d0, d0, d1
     138: fc1d83a0     	stur	d0, [x29, #-40]
     13c: 14000001     	b	0x140 <_main+0xe8>
     140: b85d43a8     	ldur	w8, [x29, #-44]
     144: 11000508     	add	w8, w8, #1
     148: b81d43a8     	stur	w8, [x29, #-44]
     14c: 17ffffea     	b	0xf4 <_main+0x9c>
     150: f9400fe0     	ldr	x0, [sp, #24]
     154: fc5e03a0     	ldur	d0, [x29, #-32]
     158: fc5d83a1     	ldur	d1, [x29, #-40]
     15c: 1e611800     	fdiv	d0, d0, d1
     160: fd0017e0     	str	d0, [sp, #40]
     164: 90000001     	adrp	x1, 0x0 <_main+0x10c>
     168: 91000021     	add	x1, x1, #0
     16c: 94000000     	bl	0x16c <_main+0x114>
     170: fd4017e0     	ldr	d0, [sp, #40]
     174: 94000000     	bl	0x174 <_main+0x11c>
     178: 90000001     	adrp	x1, 0x0 <_main+0x120>
     17c: 91000021     	add	x1, x1, #0
     180: 94000000     	bl	0x180 <_main+0x128>
     184: f9400fe0     	ldr	x0, [sp, #24]
     188: 90000001     	adrp	x1, 0x0 <_main+0x130>
     18c: 91000021     	add	x1, x1, #0
     190: 94000000     	bl	0x190 <_main+0x138>
     194: f94013e0     	ldr	x0, [sp, #32]
     198: d10057a1     	sub	x1, x29, #21
     19c: 94000000     	bl	0x19c <_main+0x144>
     1a0: 14000001     	b	0x1a4 <_main+0x14c>
     1a4: 38deb3a8     	ldursb	w8, [x29, #-21]
     1a8: 7101e508     	subs	w8, w8, #121
     1ac: 1a9f17e8     	cset	w8, eq
     1b0: 52800029     	mov	w9, #1
     1b4: b90007e9     	str	w9, [sp, #4]
     1b8: 370000e8     	tbnz	w8, #0, 0x1d4 <_main+0x17c>
     1bc: 14000001     	b	0x1c0 <_main+0x168>
     1c0: 38deb3a8     	ldursb	w8, [x29, #-21]
     1c4: 71016508     	subs	w8, w8, #89
     1c8: 1a9f17e8     	cset	w8, eq
     1cc: b90007e8     	str	w8, [sp, #4]
     1d0: 14000001     	b	0x1d4 <_main+0x17c>
     1d4: b94007e8     	ldr	w8, [sp, #4]
     1d8: 3707f568     	tbnz	w8, #0, 0x84 <_main+0x2c>
     1dc: 14000001     	b	0x1e0 <_main+0x188>
     1e0: 52800000     	mov	w0, #0
     1e4: a9467bfd     	ldp	x29, x30, [sp, #96]
     1e8: 9101c3ff     	add	sp, sp, #112
     1ec: d65f03c0     	ret

00000000000001f0 <__ZNSt3__1lsB8ue170006INS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc>:
     1f0: d100c3ff     	sub	sp, sp, #48
     1f4: a9027bfd     	stp	x29, x30, [sp, #32]
     1f8: 910083fd     	add	x29, sp, #32
     1fc: f81f83a0     	stur	x0, [x29, #-8]
     200: f9000be1     	str	x1, [sp, #16]
     204: f85f83a8     	ldur	x8, [x29, #-8]
     208: f90007e8     	str	x8, [sp, #8]
     20c: f9400be8     	ldr	x8, [sp, #16]
     210: f90003e8     	str	x8, [sp]
     214: f9400be0     	ldr	x0, [sp, #16]
     218: 94000000     	bl	0x218 <__ZNSt3__1lsB8ue170006INS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc+0x28>
     21c: f94003e1     	ldr	x1, [sp]
     220: aa0003e2     	mov	x2, x0
     224: f94007e0     	ldr	x0, [sp, #8]
     228: 94000000     	bl	0x228 <__ZNSt3__1lsB8ue170006INS_11char_traitsIcEEEERNS_13basic_ostreamIcT_EES6_PKc+0x38>
     22c: a9427bfd     	ldp	x29, x30, [sp, #32]
     230: 9100c3ff     	add	sp, sp, #48
     234: d65f03c0     	ret

0000000000000238 <__Z3powB8ue170006IdiENSt3__19enable_ifIXaasr3std13is_arithmeticIT_EE5valuesr3std13is_arithmeticIT0_EE5valueENS0_9__promoteIS2_S3_vEEE4type4typeES2_S3_>:
     238: d10083ff     	sub	sp, sp, #32
     23c: a9017bfd     	stp	x29, x30, [sp, #16]
     240: 910043fd     	add	x29, sp, #16
     244: fd0007e0     	str	d0, [sp, #8]
     248: b90007e0     	str	w0, [sp, #4]
     24c: fd4007e0     	ldr	d0, [sp, #8]
     250: bd4007e2     	ldr	s2, [sp, #4]
     254: 1e204041     	fmov	s1, s2
     258: 0f20a421     	sshll.2d	v1, v1, #0
     25c: 5e61d821     	scvtf	d1, d1
     260: 94000000     	bl	0x260 <__Z3powB8ue170006IdiENSt3__19enable_ifIXaasr3std13is_arithmeticIT_EE5valuesr3std13is_arithmeticIT0_EE5valueENS0_9__promoteIS2_S3_vEEE4type4typeES2_S3_+0x28>
     264: a9417bfd     	ldp	x29, x30, [sp, #16]
     268: 910083ff     	add	sp, sp, #32
     26c: d65f03c0     	ret

0000000000000270 <__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsB8ue170006EPFRS3_S4_E>:
     270: d10083ff     	sub	sp, sp, #32
     274: a9017bfd     	stp	x29, x30, [sp, #16]
     278: 910043fd     	add	x29, sp, #16
     27c: f90007e0     	str	x0, [sp, #8]
     280: f90003e1     	str	x1, [sp]
     284: f94007e0     	ldr	x0, [sp, #8]
     288: f94003e8     	ldr	x8, [sp]
     28c: d63f0100     	blr	x8
     290: a9417bfd     	ldp	x29, x30, [sp, #16]
     294: 910083ff     	add	sp, sp, #32
     298: d65f03c0     	ret

000000000000029c <__ZNSt3__14endlB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_>:
     29c: d10083ff     	sub	sp, sp, #32
     2a0: a9017bfd     	stp	x29, x30, [sp, #16]
     2a4: 910043fd     	add	x29, sp, #16
     2a8: f90007e0     	str	x0, [sp, #8]
     2ac: f94007e8     	ldr	x8, [sp, #8]
     2b0: f90003e8     	str	x8, [sp]
     2b4: f94007e8     	ldr	x8, [sp, #8]
     2b8: f9400109     	ldr	x9, [x8]
     2bc: f85e8129     	ldur	x9, [x9, #-24]
     2c0: 8b090100     	add	x0, x8, x9
     2c4: 52800141     	mov	w1, #10
     2c8: 94000000     	bl	0x2c8 <__ZNSt3__14endlB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_+0x2c>
     2cc: aa0003e8     	mov	x8, x0
     2d0: f94003e0     	ldr	x0, [sp]
     2d4: 13001d01     	sxtb	w1, w8
     2d8: 94000000     	bl	0x2d8 <__ZNSt3__14endlB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_+0x3c>
     2dc: f94007e0     	ldr	x0, [sp, #8]
     2e0: 94000000     	bl	0x2e0 <__ZNSt3__14endlB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_+0x44>
     2e4: f94007e0     	ldr	x0, [sp, #8]
     2e8: a9417bfd     	ldp	x29, x30, [sp, #16]
     2ec: 910083ff     	add	sp, sp, #32
     2f0: d65f03c0     	ret

00000000000002f4 <__ZNSt3__1rsB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_istreamIT_T0_EES7_RS4_>:
     2f4: d10183ff     	sub	sp, sp, #96
     2f8: a9057bfd     	stp	x29, x30, [sp, #80]
     2fc: 910143fd     	add	x29, sp, #80
     300: f81f83a0     	stur	x0, [x29, #-8]
     304: f81f03a1     	stur	x1, [x29, #-16]
     308: 52800008     	mov	w8, #0
     30c: b81ec3bf     	stur	wzr, [x29, #-20]
     310: f85f83a1     	ldur	x1, [x29, #-8]
     314: d10057a0     	sub	x0, x29, #21
     318: f9000fe0     	str	x0, [sp, #24]
     31c: 12000102     	and	w2, w8, #0x1
     320: 94000000     	bl	0x320 <__ZNSt3__1rsB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_istreamIT_T0_EES7_RS4_+0x2c>
     324: f9400fe0     	ldr	x0, [sp, #24]
     328: 94000000     	bl	0x328 <__ZNSt3__1rsB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_istreamIT_T0_EES7_RS4_+0x34>
     32c: 360009c0     	tbz	w0, #0, 0x464 <__ZNSt3__1rsB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_istreamIT_T0_EES7_RS4_+0x170>
     330: 14000001     	b	0x334 <__ZNSt3__1rsB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_istreamIT_T0_EES7_RS4_+0x40>
     334: f85f83a8     	ldur	x8, [x29, #-8]
     338: f9400109     	ldr	x9, [x8]
     33c: f85e8129     	ldur	x9, [x9, #-24]
     340: 8b090100     	add	x0, x8, x9
     344: 94000000     	bl	0x344 <__ZNSt3__1rsB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_istreamIT_T0_EES7_RS4_+0x50>
     348: f9000be0     	str	x0, [sp, #16]
     34c: 14000001     	b	0x350 <__ZNSt3__1rsB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_istreamIT_T0_EES7_RS4_+0x5c>
     350: f9400be0     	ldr	x0, [sp, #16]
     354: 94000000     	bl	0x354 <__ZNSt3__1rsB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_istreamIT_T0_EES7_RS4_+0x60>
     358: b9000fe0     	str	w0, [sp, #12]
     35c: 14000001     	b	0x360 <__ZNSt3__1rsB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_istreamIT_T0_EES7_RS4_+0x6c>
     360: b9400fe8     	ldr	w8, [sp, #12]
     364: b81e43a8     	stur	w8, [x29, #-28]
     368: b85e43a8     	ldur	w8, [x29, #-28]
     36c: b9000be8     	str	w8, [sp, #8]
     370: 94000000     	bl	0x370 <__ZNSt3__1rsB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_istreamIT_T0_EES7_RS4_+0x7c>
     374: aa0003e1     	mov	x1, x0
     378: b9400be0     	ldr	w0, [sp, #8]
     37c: 94000000     	bl	0x37c <__ZNSt3__1rsB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_istreamIT_T0_EES7_RS4_+0x88>
     380: 36000480     	tbz	w0, #0, 0x410 <__ZNSt3__1rsB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_istreamIT_T0_EES7_RS4_+0x11c>
     384: 14000001     	b	0x388 <__ZNSt3__1rsB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_istreamIT_T0_EES7_RS4_+0x94>
     388: b85ec3a8     	ldur	w8, [x29, #-20]
     38c: 321f0508     	orr	w8, w8, #0x6
     390: b81ec3a8     	stur	w8, [x29, #-20]
     394: 14000024     	b	0x424 <__ZNSt3__1rsB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_istreamIT_T0_EES7_RS4_+0x130>
     398: f90017e0     	str	x0, [sp, #40]
     39c: aa0103e8     	mov	x8, x1
     3a0: b90027e8     	str	w8, [sp, #36]
     3a4: 14000001     	b	0x3a8 <__ZNSt3__1rsB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_istreamIT_T0_EES7_RS4_+0xb4>
     3a8: f94017e0     	ldr	x0, [sp, #40]
     3ac: 94000000     	bl	0x3ac <__ZNSt3__1rsB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_istreamIT_T0_EES7_RS4_+0xb8>
     3b0: b85ec3a8     	ldur	w8, [x29, #-20]
     3b4: 32000108     	orr	w8, w8, #0x1
     3b8: b81ec3a8     	stur	w8, [x29, #-20]
     3bc: f85f83a8     	ldur	x8, [x29, #-8]
     3c0: f9400109     	ldr	x9, [x8]
     3c4: f85e8129     	ldur	x9, [x9, #-24]
     3c8: 8b090100     	add	x0, x8, x9
     3cc: b85ec3a1     	ldur	w1, [x29, #-20]
     3d0: 94000000     	bl	0x3d0 <__ZNSt3__1rsB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_istreamIT_T0_EES7_RS4_+0xdc>
     3d4: 14000001     	b	0x3d8 <__ZNSt3__1rsB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_istreamIT_T0_EES7_RS4_+0xe4>
     3d8: f85f83a8     	ldur	x8, [x29, #-8]
     3dc: f9400109     	ldr	x9, [x8]
     3e0: f85e8129     	ldur	x9, [x9, #-24]
     3e4: 8b090100     	add	x0, x8, x9
     3e8: 94000000     	bl	0x3e8 <__ZNSt3__1rsB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_istreamIT_T0_EES7_RS4_+0xf4>
     3ec: b90007e0     	str	w0, [sp, #4]
     3f0: 14000001     	b	0x3f4 <__ZNSt3__1rsB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_istreamIT_T0_EES7_RS4_+0x100>
     3f4: b94007e8     	ldr	w8, [sp, #4]
     3f8: 72000108     	ands	w8, w8, #0x1
     3fc: 1a9f17e8     	cset	w8, eq
     400: 370001e8     	tbnz	w8, #0, 0x43c <__ZNSt3__1rsB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_istreamIT_T0_EES7_RS4_+0x148>
     404: 14000001     	b	0x408 <__ZNSt3__1rsB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_istreamIT_T0_EES7_RS4_+0x114>
     408: 94000000     	bl	0x408 <__ZNSt3__1rsB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_istreamIT_T0_EES7_RS4_+0x114>
     40c: 1400001d     	b	0x480 <__ZNSt3__1rsB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_istreamIT_T0_EES7_RS4_+0x18c>
     410: b85e43a0     	ldur	w0, [x29, #-28]
     414: 94000000     	bl	0x414 <__ZNSt3__1rsB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_istreamIT_T0_EES7_RS4_+0x120>
     418: f85f03a8     	ldur	x8, [x29, #-16]
     41c: 39000100     	strb	w0, [x8]
     420: 14000001     	b	0x424 <__ZNSt3__1rsB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_istreamIT_T0_EES7_RS4_+0x130>
     424: 14000008     	b	0x444 <__ZNSt3__1rsB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_istreamIT_T0_EES7_RS4_+0x150>
     428: f90017e0     	str	x0, [sp, #40]
     42c: aa0103e8     	mov	x8, x1
     430: b90027e8     	str	w8, [sp, #36]
     434: 94000000     	bl	0x434 <__ZNSt3__1rsB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_istreamIT_T0_EES7_RS4_+0x140>
     438: 1400000a     	b	0x460 <__ZNSt3__1rsB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_istreamIT_T0_EES7_RS4_+0x16c>
     43c: 94000000     	bl	0x43c <__ZNSt3__1rsB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_istreamIT_T0_EES7_RS4_+0x148>
     440: 14000001     	b	0x444 <__ZNSt3__1rsB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_istreamIT_T0_EES7_RS4_+0x150>
     444: f85f83a8     	ldur	x8, [x29, #-8]
     448: f9400109     	ldr	x9, [x8]
     44c: f85e8129     	ldur	x9, [x9, #-24]
     450: 8b090100     	add	x0, x8, x9
     454: b85ec3a1     	ldur	w1, [x29, #-20]
     458: 94000000     	bl	0x458 <__ZNSt3__1rsB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_istreamIT_T0_EES7_RS4_+0x164>
     45c: 14000002     	b	0x464 <__ZNSt3__1rsB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_istreamIT_T0_EES7_RS4_+0x170>
     460: 14000005     	b	0x474 <__ZNSt3__1rsB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_istreamIT_T0_EES7_RS4_+0x180>
     464: f85f83a0     	ldur	x0, [x29, #-8]
     468: a9457bfd     	ldp	x29, x30, [sp, #80]
     46c: 910183ff     	add	sp, sp, #96
     470: d65f03c0     	ret
     474: f94017e0     	ldr	x0, [sp, #40]
     478: 94000000     	bl	0x478 <__ZNSt3__1rsB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_istreamIT_T0_EES7_RS4_+0x184>
     47c: 94000000     	bl	0x47c <__ZNSt3__1rsB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_istreamIT_T0_EES7_RS4_+0x188>
     480: d4200020     	brk	#0x1

0000000000000484 <__ZNSt3__124__put_character_sequenceB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m>:
     484: d10283ff     	sub	sp, sp, #160
     488: a9097bfd     	stp	x29, x30, [sp, #144]
     48c: 910243fd     	add	x29, sp, #144
     490: f81f83a0     	stur	x0, [x29, #-8]
     494: f81f03a1     	stur	x1, [x29, #-16]
     498: f81e83a2     	stur	x2, [x29, #-24]
     49c: f85f83a1     	ldur	x1, [x29, #-8]
     4a0: d100a3a0     	sub	x0, x29, #40
     4a4: 94000000     	bl	0x4a4 <__ZNSt3__124__put_character_sequenceB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0x20>
     4a8: 14000001     	b	0x4ac <__ZNSt3__124__put_character_sequenceB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0x28>
     4ac: d100a3a0     	sub	x0, x29, #40
     4b0: 94000000     	bl	0x4b0 <__ZNSt3__124__put_character_sequenceB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0x2c>
     4b4: b90047e0     	str	w0, [sp, #68]
     4b8: 14000001     	b	0x4bc <__ZNSt3__124__put_character_sequenceB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0x38>
     4bc: b94047e8     	ldr	w8, [sp, #68]
     4c0: 36000a48     	tbz	w8, #0, 0x608 <__ZNSt3__124__put_character_sequenceB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0x184>
     4c4: 14000001     	b	0x4c8 <__ZNSt3__124__put_character_sequenceB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0x44>
     4c8: f85f83a1     	ldur	x1, [x29, #-8]
     4cc: 910123e0     	add	x0, sp, #72
     4d0: 94000000     	bl	0x4d0 <__ZNSt3__124__put_character_sequenceB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0x4c>
     4d4: f85f03a8     	ldur	x8, [x29, #-16]
     4d8: f9001fe8     	str	x8, [sp, #56]
     4dc: f85f83a8     	ldur	x8, [x29, #-8]
     4e0: f9400109     	ldr	x9, [x8]
     4e4: f85e8129     	ldur	x9, [x9, #-24]
     4e8: 8b090100     	add	x0, x8, x9
     4ec: 94000000     	bl	0x4ec <__ZNSt3__124__put_character_sequenceB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0x68>
     4f0: b90043e0     	str	w0, [sp, #64]
     4f4: 14000001     	b	0x4f8 <__ZNSt3__124__put_character_sequenceB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0x74>
     4f8: b94043e8     	ldr	w8, [sp, #64]
     4fc: 52801609     	mov	w9, #176
     500: 0a090108     	and	w8, w8, w9
     504: 71008108     	subs	w8, w8, #32
     508: 1a9f07e8     	cset	w8, ne
     50c: 370000e8     	tbnz	w8, #0, 0x528 <__ZNSt3__124__put_character_sequenceB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0xa4>
     510: 14000001     	b	0x514 <__ZNSt3__124__put_character_sequenceB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0x90>
     514: f85f03a8     	ldur	x8, [x29, #-16]
     518: f85e83a9     	ldur	x9, [x29, #-24]
     51c: 8b090108     	add	x8, x8, x9
     520: f9001be8     	str	x8, [sp, #48]
     524: 14000004     	b	0x534 <__ZNSt3__124__put_character_sequenceB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0xb0>
     528: f85f03a8     	ldur	x8, [x29, #-16]
     52c: f9001be8     	str	x8, [sp, #48]
     530: 14000001     	b	0x534 <__ZNSt3__124__put_character_sequenceB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0xb0>
     534: f9401be8     	ldr	x8, [sp, #48]
     538: f9000be8     	str	x8, [sp, #16]
     53c: f85f03a8     	ldur	x8, [x29, #-16]
     540: f85e83a9     	ldur	x9, [x29, #-24]
     544: 8b090108     	add	x8, x8, x9
     548: f9000fe8     	str	x8, [sp, #24]
     54c: f85f83a8     	ldur	x8, [x29, #-8]
     550: f9400109     	ldr	x9, [x8]
     554: f85e8129     	ldur	x9, [x9, #-24]
     558: 8b090108     	add	x8, x8, x9
     55c: f90013e8     	str	x8, [sp, #32]
     560: f85f83a8     	ldur	x8, [x29, #-8]
     564: f9400109     	ldr	x9, [x8]
     568: f85e8129     	ldur	x9, [x9, #-24]
     56c: 8b090100     	add	x0, x8, x9
     570: 94000000     	bl	0x570 <__ZNSt3__124__put_character_sequenceB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0xec>
     574: b9002fe0     	str	w0, [sp, #44]
     578: 14000001     	b	0x57c <__ZNSt3__124__put_character_sequenceB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0xf8>
     57c: b9402fe8     	ldr	w8, [sp, #44]
     580: f94013e4     	ldr	x4, [sp, #32]
     584: f9400fe3     	ldr	x3, [sp, #24]
     588: f9400be2     	ldr	x2, [sp, #16]
     58c: f9401fe1     	ldr	x1, [sp, #56]
     590: f94027e0     	ldr	x0, [sp, #72]
     594: 13001d05     	sxtb	w5, w8
     598: 94000000     	bl	0x598 <__ZNSt3__124__put_character_sequenceB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0x114>
     59c: f90007e0     	str	x0, [sp, #8]
     5a0: 14000001     	b	0x5a4 <__ZNSt3__124__put_character_sequenceB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0x120>
     5a4: f94007e8     	ldr	x8, [sp, #8]
     5a8: d10103a0     	sub	x0, x29, #64
     5ac: f81c03a8     	stur	x8, [x29, #-64]
     5b0: 94000000     	bl	0x5b0 <__ZNSt3__124__put_character_sequenceB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0x12c>
     5b4: 36000280     	tbz	w0, #0, 0x604 <__ZNSt3__124__put_character_sequenceB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0x180>
     5b8: 14000001     	b	0x5bc <__ZNSt3__124__put_character_sequenceB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0x138>
     5bc: f85f83a8     	ldur	x8, [x29, #-8]
     5c0: f9400109     	ldr	x9, [x8]
     5c4: f85e8129     	ldur	x9, [x9, #-24]
     5c8: 8b090100     	add	x0, x8, x9
     5cc: 528000a1     	mov	w1, #5
     5d0: 94000000     	bl	0x5d0 <__ZNSt3__124__put_character_sequenceB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0x14c>
     5d4: 14000001     	b	0x5d8 <__ZNSt3__124__put_character_sequenceB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0x154>
     5d8: 1400000b     	b	0x604 <__ZNSt3__124__put_character_sequenceB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0x180>
     5dc: f81d03a0     	stur	x0, [x29, #-48]
     5e0: aa0103e8     	mov	x8, x1
     5e4: b81cc3a8     	stur	w8, [x29, #-52]
     5e8: 1400000d     	b	0x61c <__ZNSt3__124__put_character_sequenceB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0x198>
     5ec: f81d03a0     	stur	x0, [x29, #-48]
     5f0: aa0103e8     	mov	x8, x1
     5f4: b81cc3a8     	stur	w8, [x29, #-52]
     5f8: d100a3a0     	sub	x0, x29, #40
     5fc: 94000000     	bl	0x5fc <__ZNSt3__124__put_character_sequenceB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0x178>
     600: 14000006     	b	0x618 <__ZNSt3__124__put_character_sequenceB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0x194>
     604: 14000001     	b	0x608 <__ZNSt3__124__put_character_sequenceB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0x184>
     608: d100a3a0     	sub	x0, x29, #40
     60c: 94000000     	bl	0x60c <__ZNSt3__124__put_character_sequenceB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0x188>
     610: 14000001     	b	0x614 <__ZNSt3__124__put_character_sequenceB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0x190>
     614: 1400000c     	b	0x644 <__ZNSt3__124__put_character_sequenceB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0x1c0>
     618: 14000001     	b	0x61c <__ZNSt3__124__put_character_sequenceB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0x198>
     61c: f85d03a0     	ldur	x0, [x29, #-48]
     620: 94000000     	bl	0x620 <__ZNSt3__124__put_character_sequenceB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0x19c>
     624: f85f83a8     	ldur	x8, [x29, #-8]
     628: f9400109     	ldr	x9, [x8]
     62c: f85e8129     	ldur	x9, [x9, #-24]
     630: 8b090100     	add	x0, x8, x9
     634: 94000000     	bl	0x634 <__ZNSt3__124__put_character_sequenceB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0x1b0>
     638: 14000001     	b	0x63c <__ZNSt3__124__put_character_sequenceB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0x1b8>
     63c: 94000000     	bl	0x63c <__ZNSt3__124__put_character_sequenceB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0x1b8>
     640: 14000001     	b	0x644 <__ZNSt3__124__put_character_sequenceB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0x1c0>
     644: f85f83a0     	ldur	x0, [x29, #-8]
     648: a9497bfd     	ldp	x29, x30, [sp, #144]
     64c: 910283ff     	add	sp, sp, #160
     650: d65f03c0     	ret
     654: f81d03a0     	stur	x0, [x29, #-48]
     658: aa0103e8     	mov	x8, x1
     65c: b81cc3a8     	stur	w8, [x29, #-52]
     660: 94000000     	bl	0x660 <__ZNSt3__124__put_character_sequenceB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0x1dc>
     664: 14000001     	b	0x668 <__ZNSt3__124__put_character_sequenceB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0x1e4>
     668: 14000001     	b	0x66c <__ZNSt3__124__put_character_sequenceB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0x1e8>
     66c: f85d03a0     	ldur	x0, [x29, #-48]
     670: 94000000     	bl	0x670 <__ZNSt3__124__put_character_sequenceB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0x1ec>
     674: 94000000     	bl	0x674 <__ZNSt3__124__put_character_sequenceB8ue170006IcNS_11char_traitsIcEEEERNS_13basic_ostreamIT_T0_EES7_PKS4_m+0x1f0>

0000000000000678 <__ZNSt3__111char_traitsIcE6lengthB8ue170006EPKc>:
     678: d100c3ff     	sub	sp, sp, #48
     67c: a9027bfd     	stp	x29, x30, [sp, #32]
     680: 910083fd     	add	x29, sp, #32
     684: f81f83a0     	stur	x0, [x29, #-8]
     688: f85f83a0     	ldur	x0, [x29, #-8]
     68c: 94000000     	bl	0x68c <__ZNSt3__111char_traitsIcE6lengthB8ue170006EPKc+0x14>
     690: f90003e0     	str	x0, [sp]
     694: 14000001     	b	0x698 <__ZNSt3__111char_traitsIcE6lengthB8ue170006EPKc+0x20>
     698: f94003e0     	ldr	x0, [sp]
     69c: a9427bfd     	ldp	x29, x30, [sp, #32]
     6a0: 9100c3ff     	add	sp, sp, #48
     6a4: d65f03c0     	ret
     6a8: f9000be0     	str	x0, [sp, #16]
     6ac: aa0103e8     	mov	x8, x1
     6b0: b9000fe8     	str	w8, [sp, #12]
     6b4: 14000001     	b	0x6b8 <__ZNSt3__111char_traitsIcE6lengthB8ue170006EPKc+0x40>
     6b8: f9400be0     	ldr	x0, [sp, #16]
     6bc: 94000000     	bl	0x6bc <__ZNSt3__111char_traitsIcE6lengthB8ue170006EPKc+0x44>

00000000000006c0 <__ZNKSt3__113basic_ostreamIcNS_11char_traitsIcEEE6sentrycvbB8ue170006Ev>:
     6c0: d10043ff     	sub	sp, sp, #16
     6c4: f90007e0     	str	x0, [sp, #8]
     6c8: f94007e8     	ldr	x8, [sp, #8]
     6cc: 39400108     	ldrb	w8, [x8]
     6d0: 12000100     	and	w0, w8, #0x1
     6d4: 910043ff     	add	sp, sp, #16
     6d8: d65f03c0     	ret

00000000000006dc <__ZNSt3__116__pad_and_outputB8ue170006IcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_>:
     6dc: d10283ff     	sub	sp, sp, #160
     6e0: a9097bfd     	stp	x29, x30, [sp, #144]
     6e4: 910243fd     	add	x29, sp, #144
     6e8: f81f03a0     	stur	x0, [x29, #-16]
     6ec: f81e83a1     	stur	x1, [x29, #-24]
     6f0: f81e03a2     	stur	x2, [x29, #-32]
     6f4: f81d83a3     	stur	x3, [x29, #-40]
     6f8: f81d03a4     	stur	x4, [x29, #-48]
     6fc: 381cf3a5     	sturb	w5, [x29, #-49]
     700: f85f03a8     	ldur	x8, [x29, #-16]
     704: f1000108     	subs	x8, x8, #0
     708: 1a9f07e8     	cset	w8, ne
     70c: 370000a8     	tbnz	w8, #0, 0x720 <__ZNSt3__116__pad_and_outputB8ue170006IcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0x44>
     710: 14000001     	b	0x714 <__ZNSt3__116__pad_and_outputB8ue170006IcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0x38>
     714: f85f03a8     	ldur	x8, [x29, #-16]
     718: f81f83a8     	stur	x8, [x29, #-8]
     71c: 1400007b     	b	0x908 <__ZNSt3__116__pad_and_outputB8ue170006IcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0x22c>
     720: f85d83a8     	ldur	x8, [x29, #-40]
     724: f85e83a9     	ldur	x9, [x29, #-24]
     728: eb090108     	subs	x8, x8, x9
     72c: f81c03a8     	stur	x8, [x29, #-64]
     730: f85d03a0     	ldur	x0, [x29, #-48]
     734: 94000000     	bl	0x734 <__ZNSt3__116__pad_and_outputB8ue170006IcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0x58>
     738: f90027e0     	str	x0, [sp, #72]
     73c: f94027e8     	ldr	x8, [sp, #72]
     740: f85c03a9     	ldur	x9, [x29, #-64]
     744: eb090108     	subs	x8, x8, x9
     748: 1a9fc7e8     	cset	w8, le
     74c: 370000e8     	tbnz	w8, #0, 0x768 <__ZNSt3__116__pad_and_outputB8ue170006IcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0x8c>
     750: 14000001     	b	0x754 <__ZNSt3__116__pad_and_outputB8ue170006IcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0x78>
     754: f85c03a9     	ldur	x9, [x29, #-64]
     758: f94027e8     	ldr	x8, [sp, #72]
     75c: eb090108     	subs	x8, x8, x9
     760: f90027e8     	str	x8, [sp, #72]
     764: 14000003     	b	0x770 <__ZNSt3__116__pad_and_outputB8ue170006IcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0x94>
     768: f90027ff     	str	xzr, [sp, #72]
     76c: 14000001     	b	0x770 <__ZNSt3__116__pad_and_outputB8ue170006IcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0x94>
     770: f85e03a8     	ldur	x8, [x29, #-32]
     774: f85e83a9     	ldur	x9, [x29, #-24]
     778: eb090108     	subs	x8, x8, x9
     77c: f90023e8     	str	x8, [sp, #64]
     780: f94023e8     	ldr	x8, [sp, #64]
     784: f1000108     	subs	x8, x8, #0
     788: 1a9fc7e8     	cset	w8, le
     78c: 37000208     	tbnz	w8, #0, 0x7cc <__ZNSt3__116__pad_and_outputB8ue170006IcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0xf0>
     790: 14000001     	b	0x794 <__ZNSt3__116__pad_and_outputB8ue170006IcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0xb8>
     794: f85f03a0     	ldur	x0, [x29, #-16]
     798: f85e83a1     	ldur	x1, [x29, #-24]
     79c: f94023e2     	ldr	x2, [sp, #64]
     7a0: 94000000     	bl	0x7a0 <__ZNSt3__116__pad_and_outputB8ue170006IcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0xc4>
     7a4: f94023e8     	ldr	x8, [sp, #64]
     7a8: eb080008     	subs	x8, x0, x8
     7ac: 1a9f17e8     	cset	w8, eq
     7b0: 370000c8     	tbnz	w8, #0, 0x7c8 <__ZNSt3__116__pad_and_outputB8ue170006IcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0xec>
     7b4: 14000001     	b	0x7b8 <__ZNSt3__116__pad_and_outputB8ue170006IcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0xdc>
     7b8: f81f03bf     	stur	xzr, [x29, #-16]
     7bc: f85f03a8     	ldur	x8, [x29, #-16]
     7c0: f81f83a8     	stur	x8, [x29, #-8]
     7c4: 14000051     	b	0x908 <__ZNSt3__116__pad_and_outputB8ue170006IcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0x22c>
     7c8: 14000001     	b	0x7cc <__ZNSt3__116__pad_and_outputB8ue170006IcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0xf0>
     7cc: f94027e8     	ldr	x8, [sp, #72]
     7d0: f1000108     	subs	x8, x8, #0
     7d4: 1a9fc7e8     	cset	w8, le
     7d8: 370005e8     	tbnz	w8, #0, 0x894 <__ZNSt3__116__pad_and_outputB8ue170006IcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0x1b8>
     7dc: 14000001     	b	0x7e0 <__ZNSt3__116__pad_and_outputB8ue170006IcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0x104>
     7e0: f94027e1     	ldr	x1, [sp, #72]
     7e4: 38dcf3a2     	ldursb	w2, [x29, #-49]
     7e8: 9100a3e0     	add	x0, sp, #40
     7ec: f90003e0     	str	x0, [sp]
     7f0: 94000000     	bl	0x7f0 <__ZNSt3__116__pad_and_outputB8ue170006IcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0x114>
     7f4: f94003e0     	ldr	x0, [sp]
     7f8: f85f03a8     	ldur	x8, [x29, #-16]
     7fc: f90007e8     	str	x8, [sp, #8]
     800: 94000000     	bl	0x800 <__ZNSt3__116__pad_and_outputB8ue170006IcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0x124>
     804: aa0003e1     	mov	x1, x0
     808: f94007e0     	ldr	x0, [sp, #8]
     80c: f94027e2     	ldr	x2, [sp, #72]
     810: 94000000     	bl	0x810 <__ZNSt3__116__pad_and_outputB8ue170006IcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0x134>
     814: f9000be0     	str	x0, [sp, #16]
     818: 14000001     	b	0x81c <__ZNSt3__116__pad_and_outputB8ue170006IcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0x140>
     81c: f9400be8     	ldr	x8, [sp, #16]
     820: f94027e9     	ldr	x9, [sp, #72]
     824: eb090108     	subs	x8, x8, x9
     828: 1a9f17e8     	cset	w8, eq
     82c: 370001c8     	tbnz	w8, #0, 0x864 <__ZNSt3__116__pad_and_outputB8ue170006IcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0x188>
     830: 14000001     	b	0x834 <__ZNSt3__116__pad_and_outputB8ue170006IcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0x158>
     834: f81f03bf     	stur	xzr, [x29, #-16]
     838: f85f03a8     	ldur	x8, [x29, #-16]
     83c: f81f83a8     	stur	x8, [x29, #-8]
     840: 52800028     	mov	w8, #1
     844: b9001be8     	str	w8, [sp, #24]
     848: 14000009     	b	0x86c <__ZNSt3__116__pad_and_outputB8ue170006IcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0x190>
     84c: f90013e0     	str	x0, [sp, #32]
     850: aa0103e8     	mov	x8, x1
     854: b9001fe8     	str	w8, [sp, #28]
     858: 9100a3e0     	add	x0, sp, #40
     85c: 94000000     	bl	0x85c <__ZNSt3__116__pad_and_outputB8ue170006IcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0x180>
     860: 1400000c     	b	0x890 <__ZNSt3__116__pad_and_outputB8ue170006IcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0x1b4>
     864: b9001bff     	str	wzr, [sp, #24]
     868: 14000001     	b	0x86c <__ZNSt3__116__pad_and_outputB8ue170006IcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0x190>
     86c: 9100a3e0     	add	x0, sp, #40
     870: 94000000     	bl	0x870 <__ZNSt3__116__pad_and_outputB8ue170006IcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0x194>
     874: b9401be8     	ldr	w8, [sp, #24]
     878: 71000108     	subs	w8, w8, #0
     87c: 1a9f17e8     	cset	w8, eq
     880: 37000068     	tbnz	w8, #0, 0x88c <__ZNSt3__116__pad_and_outputB8ue170006IcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0x1b0>
     884: 14000001     	b	0x888 <__ZNSt3__116__pad_and_outputB8ue170006IcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0x1ac>
     888: 14000020     	b	0x908 <__ZNSt3__116__pad_and_outputB8ue170006IcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0x22c>
     88c: 14000002     	b	0x894 <__ZNSt3__116__pad_and_outputB8ue170006IcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0x1b8>
     890: 14000022     	b	0x918 <__ZNSt3__116__pad_and_outputB8ue170006IcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0x23c>
     894: f85d83a8     	ldur	x8, [x29, #-40]
     898: f85e03a9     	ldur	x9, [x29, #-32]
     89c: eb090108     	subs	x8, x8, x9
     8a0: f90023e8     	str	x8, [sp, #64]
     8a4: f94023e8     	ldr	x8, [sp, #64]
     8a8: f1000108     	subs	x8, x8, #0
     8ac: 1a9fc7e8     	cset	w8, le
     8b0: 37000208     	tbnz	w8, #0, 0x8f0 <__ZNSt3__116__pad_and_outputB8ue170006IcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0x214>
     8b4: 14000001     	b	0x8b8 <__ZNSt3__116__pad_and_outputB8ue170006IcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0x1dc>
     8b8: f85f03a0     	ldur	x0, [x29, #-16]
     8bc: f85e03a1     	ldur	x1, [x29, #-32]
     8c0: f94023e2     	ldr	x2, [sp, #64]
     8c4: 94000000     	bl	0x8c4 <__ZNSt3__116__pad_and_outputB8ue170006IcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0x1e8>
     8c8: f94023e8     	ldr	x8, [sp, #64]
     8cc: eb080008     	subs	x8, x0, x8
     8d0: 1a9f17e8     	cset	w8, eq
     8d4: 370000c8     	tbnz	w8, #0, 0x8ec <__ZNSt3__116__pad_and_outputB8ue170006IcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0x210>
     8d8: 14000001     	b	0x8dc <__ZNSt3__116__pad_and_outputB8ue170006IcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0x200>
     8dc: f81f03bf     	stur	xzr, [x29, #-16]
     8e0: f85f03a8     	ldur	x8, [x29, #-16]
     8e4: f81f83a8     	stur	x8, [x29, #-8]
     8e8: 14000008     	b	0x908 <__ZNSt3__116__pad_and_outputB8ue170006IcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0x22c>
     8ec: 14000001     	b	0x8f0 <__ZNSt3__116__pad_and_outputB8ue170006IcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0x214>
     8f0: f85d03a0     	ldur	x0, [x29, #-48]
     8f4: d2800001     	mov	x1, #0
     8f8: 94000000     	bl	0x8f8 <__ZNSt3__116__pad_and_outputB8ue170006IcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0x21c>
     8fc: f85f03a8     	ldur	x8, [x29, #-16]
     900: f81f83a8     	stur	x8, [x29, #-8]
     904: 14000001     	b	0x908 <__ZNSt3__116__pad_and_outputB8ue170006IcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0x22c>
     908: f85f83a0     	ldur	x0, [x29, #-8]
     90c: a9497bfd     	ldp	x29, x30, [sp, #144]
     910: 910283ff     	add	sp, sp, #160
     914: d65f03c0     	ret
     918: f94013e0     	ldr	x0, [sp, #32]
     91c: 94000000     	bl	0x91c <__ZNSt3__116__pad_and_outputB8ue170006IcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0x240>
     920: 94000000     	bl	0x920 <__ZNSt3__116__pad_and_outputB8ue170006IcNS_11char_traitsIcEEEENS_19ostreambuf_iteratorIT_T0_EES6_PKS4_S8_S8_RNS_8ios_baseES4_+0x244>

0000000000000924 <__ZNSt3__119ostreambuf_iteratorIcNS_11char_traitsIcEEEC1B8ue170006ERNS_13basic_ostreamIcS2_EE>:
     924: d100c3ff     	sub	sp, sp, #48
     928: a9027bfd     	stp	x29, x30, [sp, #32]
     92c: 910083fd     	add	x29, sp, #32
     930: f81f83a0     	stur	x0, [x29, #-8]
     934: f9000be1     	str	x1, [sp, #16]
     938: f85f83a0     	ldur	x0, [x29, #-8]
     93c: f90007e0     	str	x0, [sp, #8]
     940: f9400be1     	ldr	x1, [sp, #16]
     944: 94000000     	bl	0x944 <__ZNSt3__119ostreambuf_iteratorIcNS_11char_traitsIcEEEC1B8ue170006ERNS_13basic_ostreamIcS2_EE+0x20>
     948: f94007e0     	ldr	x0, [sp, #8]
     94c: a9427bfd     	ldp	x29, x30, [sp, #32]
     950: 9100c3ff     	add	sp, sp, #48
     954: d65f03c0     	ret

0000000000000958 <__ZNKSt3__18ios_base5flagsB8ue170006Ev>:
     958: d10043ff     	sub	sp, sp, #16
     95c: f90007e0     	str	x0, [sp, #8]
     960: f94007e8     	ldr	x8, [sp, #8]
     964: b9400900     	ldr	w0, [x8, #8]
     968: 910043ff     	add	sp, sp, #16
     96c: d65f03c0     	ret

0000000000000970 <__ZNKSt3__19basic_iosIcNS_11char_traitsIcEEE4fillB8ue170006Ev>:
     970: d10083ff     	sub	sp, sp, #32
     974: a9017bfd     	stp	x29, x30, [sp, #16]
     978: 910043fd     	add	x29, sp, #16
     97c: f90007e0     	str	x0, [sp, #8]
     980: f94007e8     	ldr	x8, [sp, #8]
     984: f90003e8     	str	x8, [sp]
     988: 94000000     	bl	0x988 <__ZNKSt3__19basic_iosIcNS_11char_traitsIcEEE4fillB8ue170006Ev+0x18>
     98c: f94003e8     	ldr	x8, [sp]
     990: b9409101     	ldr	w1, [x8, #144]
     994: 94000000     	bl	0x994 <__ZNKSt3__19basic_iosIcNS_11char_traitsIcEEE4fillB8ue170006Ev+0x24>
     998: 36000120     	tbz	w0, #0, 0x9bc <__ZNKSt3__19basic_iosIcNS_11char_traitsIcEEE4fillB8ue170006Ev+0x4c>
     99c: 14000001     	b	0x9a0 <__ZNKSt3__19basic_iosIcNS_11char_traitsIcEEE4fillB8ue170006Ev+0x30>
     9a0: f94003e0     	ldr	x0, [sp]
     9a4: 52800401     	mov	w1, #32
     9a8: 94000000     	bl	0x9a8 <__ZNKSt3__19basic_iosIcNS_11char_traitsIcEEE4fillB8ue170006Ev+0x38>
     9ac: f94003e9     	ldr	x9, [sp]
     9b0: 13001c08     	sxtb	w8, w0
     9b4: b9009128     	str	w8, [x9, #144]
     9b8: 14000001     	b	0x9bc <__ZNKSt3__19basic_iosIcNS_11char_traitsIcEEE4fillB8ue170006Ev+0x4c>
     9bc: f94003e8     	ldr	x8, [sp]
     9c0: b9409108     	ldr	w8, [x8, #144]
     9c4: 13001d00     	sxtb	w0, w8
     9c8: a9417bfd     	ldp	x29, x30, [sp, #16]
     9cc: 910083ff     	add	sp, sp, #32
     9d0: d65f03c0     	ret

00000000000009d4 <__ZNKSt3__119ostreambuf_iteratorIcNS_11char_traitsIcEEE6failedB8ue170006Ev>:
     9d4: d10043ff     	sub	sp, sp, #16
     9d8: f90007e0     	str	x0, [sp, #8]
     9dc: f94007e8     	ldr	x8, [sp, #8]
     9e0: f9400108     	ldr	x8, [x8]
     9e4: f1000108     	subs	x8, x8, #0
     9e8: 1a9f17e8     	cset	w8, eq
     9ec: 12000100     	and	w0, w8, #0x1
     9f0: 910043ff     	add	sp, sp, #16
     9f4: d65f03c0     	ret

00000000000009f8 <__ZNSt3__19basic_iosIcNS_11char_traitsIcEEE8setstateB8ue170006Ej>:
     9f8: d10083ff     	sub	sp, sp, #32
     9fc: a9017bfd     	stp	x29, x30, [sp, #16]
     a00: 910043fd     	add	x29, sp, #16
     a04: f90007e0     	str	x0, [sp, #8]
     a08: b90007e1     	str	w1, [sp, #4]
     a0c: f94007e0     	ldr	x0, [sp, #8]
     a10: b94007e1     	ldr	w1, [sp, #4]
     a14: 94000000     	bl	0xa14 <__ZNSt3__19basic_iosIcNS_11char_traitsIcEEE8setstateB8ue170006Ej+0x1c>
     a18: a9417bfd     	ldp	x29, x30, [sp, #16]
     a1c: 910083ff     	add	sp, sp, #32
     a20: d65f03c0     	ret

0000000000000a24 <___clang_call_terminate>:
     a24: a9bf7bfd     	stp	x29, x30, [sp, #-16]!
     a28: 94000000     	bl	0xa28 <___clang_call_terminate+0x4>
     a2c: 94000000     	bl	0xa2c <___clang_call_terminate+0x8>

0000000000000a30 <__ZNKSt3__18ios_base5widthB8ue170006Ev>:
     a30: d10043ff     	sub	sp, sp, #16
     a34: f90007e0     	str	x0, [sp, #8]
     a38: f94007e8     	ldr	x8, [sp, #8]
     a3c: f9400d00     	ldr	x0, [x8, #24]
     a40: 910043ff     	add	sp, sp, #16
     a44: d65f03c0     	ret

0000000000000a48 <__ZNSt3__115basic_streambufIcNS_11char_traitsIcEEE5sputnB8ue170006EPKcl>:
     a48: d100c3ff     	sub	sp, sp, #48
     a4c: a9027bfd     	stp	x29, x30, [sp, #32]
     a50: 910083fd     	add	x29, sp, #32
     a54: f81f83a0     	stur	x0, [x29, #-8]
     a58: f9000be1     	str	x1, [sp, #16]
     a5c: f90007e2     	str	x2, [sp, #8]
     a60: f85f83a0     	ldur	x0, [x29, #-8]
     a64: f9400be1     	ldr	x1, [sp, #16]
     a68: f94007e2     	ldr	x2, [sp, #8]
     a6c: f9400008     	ldr	x8, [x0]
     a70: f9403108     	ldr	x8, [x8, #96]
     a74: d63f0100     	blr	x8
     a78: a9427bfd     	ldp	x29, x30, [sp, #32]
     a7c: 9100c3ff     	add	sp, sp, #48
     a80: d65f03c0     	ret

0000000000000a84 <__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC1B8ue170006Emc>:
     a84: d100c3ff     	sub	sp, sp, #48
     a88: a9027bfd     	stp	x29, x30, [sp, #32]
     a8c: 910083fd     	add	x29, sp, #32
     a90: f81f83a0     	stur	x0, [x29, #-8]
     a94: f9000be1     	str	x1, [sp, #16]
     a98: 39003fe2     	strb	w2, [sp, #15]
     a9c: f85f83a0     	ldur	x0, [x29, #-8]
     aa0: f90003e0     	str	x0, [sp]
     aa4: f9400be1     	ldr	x1, [sp, #16]
     aa8: 39c03fe2     	ldrsb	w2, [sp, #15]
     aac: 94000000     	bl	0xaac <__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC1B8ue170006Emc+0x28>
     ab0: f94003e0     	ldr	x0, [sp]
     ab4: a9427bfd     	ldp	x29, x30, [sp, #32]
     ab8: 9100c3ff     	add	sp, sp, #48
     abc: d65f03c0     	ret

0000000000000ac0 <__ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE4dataB8ue170006Ev>:
     ac0: d10083ff     	sub	sp, sp, #32
     ac4: a9017bfd     	stp	x29, x30, [sp, #16]
     ac8: 910043fd     	add	x29, sp, #16
     acc: f90007e0     	str	x0, [sp, #8]
     ad0: f94007e0     	ldr	x0, [sp, #8]
     ad4: 94000000     	bl	0xad4 <__ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE4dataB8ue170006Ev+0x14>
     ad8: 94000000     	bl	0xad8 <__ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE4dataB8ue170006Ev+0x18>
     adc: a9417bfd     	ldp	x29, x30, [sp, #16]
     ae0: 910083ff     	add	sp, sp, #32
     ae4: d65f03c0     	ret

0000000000000ae8 <__ZNSt3__18ios_base5widthB8ue170006El>:
     ae8: d10083ff     	sub	sp, sp, #32
     aec: f9000fe0     	str	x0, [sp, #24]
     af0: f9000be1     	str	x1, [sp, #16]
     af4: f9400fe9     	ldr	x9, [sp, #24]
     af8: f9400d28     	ldr	x8, [x9, #24]
     afc: f90007e8     	str	x8, [sp, #8]
     b00: f9400be8     	ldr	x8, [sp, #16]
     b04: f9000d28     	str	x8, [x9, #24]
     b08: f94007e0     	ldr	x0, [sp, #8]
     b0c: 910083ff     	add	sp, sp, #32
     b10: d65f03c0     	ret

0000000000000b14 <__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2B8ue170006Emc>:
     b14: d100c3ff     	sub	sp, sp, #48
     b18: a9027bfd     	stp	x29, x30, [sp, #32]
     b1c: 910083fd     	add	x29, sp, #32
     b20: f81f83a0     	stur	x0, [x29, #-8]
     b24: f9000be1     	str	x1, [sp, #16]
     b28: 39003fe2     	strb	w2, [sp, #15]
     b2c: f85f83a0     	ldur	x0, [x29, #-8]
     b30: f90003e0     	str	x0, [sp]
     b34: 91003be1     	add	x1, sp, #14
     b38: 910037e2     	add	x2, sp, #13
     b3c: 94000000     	bl	0xb3c <__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2B8ue170006Emc+0x28>
     b40: f94003e0     	ldr	x0, [sp]
     b44: f9400be1     	ldr	x1, [sp, #16]
     b48: 39c03fe2     	ldrsb	w2, [sp, #15]
     b4c: 94000000     	bl	0xb4c <__ZNSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEEC2B8ue170006Emc+0x38>
     b50: f94003e0     	ldr	x0, [sp]
     b54: a9427bfd     	ldp	x29, x30, [sp, #32]
     b58: 9100c3ff     	add	sp, sp, #48
     b5c: d65f03c0     	ret

0000000000000b60 <__ZNSt3__117__compressed_pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repES5_EC1B8ue170006INS_18__default_init_tagESA_EEOT_OT0_>:
     b60: d100c3ff     	sub	sp, sp, #48
     b64: a9027bfd     	stp	x29, x30, [sp, #32]
     b68: 910083fd     	add	x29, sp, #32
     b6c: f81f83a0     	stur	x0, [x29, #-8]
     b70: f9000be1     	str	x1, [sp, #16]
     b74: f90007e2     	str	x2, [sp, #8]
     b78: f85f83a0     	ldur	x0, [x29, #-8]
     b7c: f90003e0     	str	x0, [sp]
     b80: f9400be1     	ldr	x1, [sp, #16]
     b84: f94007e2     	ldr	x2, [sp, #8]
     b88: 94000000     	bl	0xb88 <__ZNSt3__117__compressed_pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repES5_EC1B8ue170006INS_18__default_init_tagESA_EEOT_OT0_+0x28>
     b8c: f94003e0     	ldr	x0, [sp]
     b90: a9427bfd     	ldp	x29, x30, [sp, #32]
     b94: 9100c3ff     	add	sp, sp, #48
     b98: d65f03c0     	ret

0000000000000b9c <__ZNSt3__117__compressed_pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repES5_EC2B8ue170006INS_18__default_init_tagESA_EEOT_OT0_>:
     b9c: d10103ff     	sub	sp, sp, #64
     ba0: a9037bfd     	stp	x29, x30, [sp, #48]
     ba4: 9100c3fd     	add	x29, sp, #48
     ba8: f81f83a0     	stur	x0, [x29, #-8]
     bac: f81f03a1     	stur	x1, [x29, #-16]
     bb0: f9000fe2     	str	x2, [sp, #24]
     bb4: f85f83a0     	ldur	x0, [x29, #-8]
     bb8: f90007e0     	str	x0, [sp, #8]
     bbc: 94000000     	bl	0xbbc <__ZNSt3__117__compressed_pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repES5_EC2B8ue170006INS_18__default_init_tagESA_EEOT_OT0_+0x20>
     bc0: f94007e0     	ldr	x0, [sp, #8]
     bc4: 94000000     	bl	0xbc4 <__ZNSt3__117__compressed_pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repES5_EC2B8ue170006INS_18__default_init_tagESA_EEOT_OT0_+0x28>
     bc8: f94007e0     	ldr	x0, [sp, #8]
     bcc: a9437bfd     	ldp	x29, x30, [sp, #48]
     bd0: 910103ff     	add	sp, sp, #64
     bd4: d65f03c0     	ret

0000000000000bd8 <__ZNSt3__122__compressed_pair_elemINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repELi0ELb0EEC2B8ue170006ENS_18__default_init_tagE>:
     bd8: d10043ff     	sub	sp, sp, #16
     bdc: f90003e0     	str	x0, [sp]
     be0: f94003e0     	ldr	x0, [sp]
     be4: 910043ff     	add	sp, sp, #16
     be8: d65f03c0     	ret

0000000000000bec <__ZNSt3__122__compressed_pair_elemINS_9allocatorIcEELi1ELb1EEC2B8ue170006ENS_18__default_init_tagE>:
     bec: d100c3ff     	sub	sp, sp, #48
     bf0: a9027bfd     	stp	x29, x30, [sp, #32]
     bf4: 910083fd     	add	x29, sp, #32
     bf8: f9000be0     	str	x0, [sp, #16]
     bfc: f9400be0     	ldr	x0, [sp, #16]
     c00: f90007e0     	str	x0, [sp, #8]
     c04: 94000000     	bl	0xc04 <__ZNSt3__122__compressed_pair_elemINS_9allocatorIcEELi1ELb1EEC2B8ue170006ENS_18__default_init_tagE+0x18>
     c08: f94007e0     	ldr	x0, [sp, #8]
     c0c: a9427bfd     	ldp	x29, x30, [sp, #32]
     c10: 9100c3ff     	add	sp, sp, #48
     c14: d65f03c0     	ret

0000000000000c18 <__ZNSt3__19allocatorIcEC2B8ue170006Ev>:
     c18: d10083ff     	sub	sp, sp, #32
     c1c: a9017bfd     	stp	x29, x30, [sp, #16]
     c20: 910043fd     	add	x29, sp, #16
     c24: f90007e0     	str	x0, [sp, #8]
     c28: f94007e0     	ldr	x0, [sp, #8]
     c2c: f90003e0     	str	x0, [sp]
     c30: 94000000     	bl	0xc30 <__ZNSt3__19allocatorIcEC2B8ue170006Ev+0x18>
     c34: f94003e0     	ldr	x0, [sp]
     c38: a9417bfd     	ldp	x29, x30, [sp, #16]
     c3c: 910083ff     	add	sp, sp, #32
     c40: d65f03c0     	ret

0000000000000c44 <__ZNSt3__116__non_trivial_ifILb1ENS_9allocatorIcEEEC2B8ue170006Ev>:
     c44: d10043ff     	sub	sp, sp, #16
     c48: f90007e0     	str	x0, [sp, #8]
     c4c: f94007e0     	ldr	x0, [sp, #8]
     c50: 910043ff     	add	sp, sp, #16
     c54: d65f03c0     	ret

0000000000000c58 <__ZNSt3__112__to_addressB8ue170006IKcEEPT_S3_>:
     c58: d10043ff     	sub	sp, sp, #16
     c5c: f90007e0     	str	x0, [sp, #8]
     c60: f94007e0     	ldr	x0, [sp, #8]
     c64: 910043ff     	add	sp, sp, #16
     c68: d65f03c0     	ret

0000000000000c6c <__ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE13__get_pointerB8ue170006Ev>:
     c6c: d100c3ff     	sub	sp, sp, #48
     c70: a9027bfd     	stp	x29, x30, [sp, #32]
     c74: 910083fd     	add	x29, sp, #32
     c78: f81f83a0     	stur	x0, [x29, #-8]
     c7c: f85f83a0     	ldur	x0, [x29, #-8]
     c80: f9000be0     	str	x0, [sp, #16]
     c84: 94000000     	bl	0xc84 <__ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE13__get_pointerB8ue170006Ev+0x18>
     c88: 360000c0     	tbz	w0, #0, 0xca0 <__ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE13__get_pointerB8ue170006Ev+0x34>
     c8c: 14000001     	b	0xc90 <__ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE13__get_pointerB8ue170006Ev+0x24>
     c90: f9400be0     	ldr	x0, [sp, #16]
     c94: 94000000     	bl	0xc94 <__ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE13__get_pointerB8ue170006Ev+0x28>
     c98: f90007e0     	str	x0, [sp, #8]
     c9c: 14000005     	b	0xcb0 <__ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE13__get_pointerB8ue170006Ev+0x44>
     ca0: f9400be0     	ldr	x0, [sp, #16]
     ca4: 94000000     	bl	0xca4 <__ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE13__get_pointerB8ue170006Ev+0x38>
     ca8: f90007e0     	str	x0, [sp, #8]
     cac: 14000001     	b	0xcb0 <__ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE13__get_pointerB8ue170006Ev+0x44>
     cb0: f94007e0     	ldr	x0, [sp, #8]
     cb4: a9427bfd     	ldp	x29, x30, [sp, #32]
     cb8: 9100c3ff     	add	sp, sp, #48
     cbc: d65f03c0     	ret

0000000000000cc0 <__ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9__is_longB8ue170006Ev>:
     cc0: d100c3ff     	sub	sp, sp, #48
     cc4: a9027bfd     	stp	x29, x30, [sp, #32]
     cc8: 910083fd     	add	x29, sp, #32
     ccc: f9000be0     	str	x0, [sp, #16]
     cd0: f9400be8     	ldr	x8, [sp, #16]
     cd4: f90007e8     	str	x8, [sp, #8]
     cd8: 94000000     	bl	0xcd8 <__ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9__is_longB8ue170006Ev+0x18>
     cdc: 360000e0     	tbz	w0, #0, 0xcf8 <__ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9__is_longB8ue170006Ev+0x38>
     ce0: 14000001     	b	0xce4 <__ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9__is_longB8ue170006Ev+0x24>
     ce4: 52800028     	mov	w8, #1
     ce8: 12000108     	and	w8, w8, #0x1
     cec: 12000108     	and	w8, w8, #0x1
     cf0: 381ff3a8     	sturb	w8, [x29, #-1]
     cf4: 1400000b     	b	0xd20 <__ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9__is_longB8ue170006Ev+0x60>
     cf8: f94007e0     	ldr	x0, [sp, #8]
     cfc: 94000000     	bl	0xcfc <__ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9__is_longB8ue170006Ev+0x3c>
     d00: 39405c08     	ldrb	w8, [x0, #23]
     d04: 53077d08     	lsr	w8, w8, #7
     d08: 72001d08     	ands	w8, w8, #0xff
     d0c: 1a9f07e8     	cset	w8, ne
     d10: 12000108     	and	w8, w8, #0x1
     d14: 12000108     	and	w8, w8, #0x1
     d18: 381ff3a8     	sturb	w8, [x29, #-1]
     d1c: 14000001     	b	0xd20 <__ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE9__is_longB8ue170006Ev+0x60>
     d20: 385ff3a8     	ldurb	w8, [x29, #-1]
     d24: 12000100     	and	w0, w8, #0x1
     d28: a9427bfd     	ldp	x29, x30, [sp, #32]
     d2c: 9100c3ff     	add	sp, sp, #48
     d30: d65f03c0     	ret

0000000000000d34 <__ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE18__get_long_pointerB8ue170006Ev>:
     d34: d10083ff     	sub	sp, sp, #32
     d38: a9017bfd     	stp	x29, x30, [sp, #16]
     d3c: 910043fd     	add	x29, sp, #16
     d40: f90007e0     	str	x0, [sp, #8]
     d44: f94007e0     	ldr	x0, [sp, #8]
     d48: 94000000     	bl	0xd48 <__ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE18__get_long_pointerB8ue170006Ev+0x14>
     d4c: f9400000     	ldr	x0, [x0]
     d50: a9417bfd     	ldp	x29, x30, [sp, #16]
     d54: 910083ff     	add	sp, sp, #32
     d58: d65f03c0     	ret

0000000000000d5c <__ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE19__get_short_pointerB8ue170006Ev>:
     d5c: d10083ff     	sub	sp, sp, #32
     d60: a9017bfd     	stp	x29, x30, [sp, #16]
     d64: 910043fd     	add	x29, sp, #16
     d68: f90007e0     	str	x0, [sp, #8]
     d6c: f94007e0     	ldr	x0, [sp, #8]
     d70: 94000000     	bl	0xd70 <__ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE19__get_short_pointerB8ue170006Ev+0x14>
     d74: 94000000     	bl	0xd74 <__ZNKSt3__112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE19__get_short_pointerB8ue170006Ev+0x18>
     d78: a9417bfd     	ldp	x29, x30, [sp, #16]
     d7c: 910083ff     	add	sp, sp, #32
     d80: d65f03c0     	ret

0000000000000d84 <__ZNSt3__130__libcpp_is_constant_evaluatedB8ue170006Ev>:
     d84: 52800008     	mov	w8, #0
     d88: 12000100     	and	w0, w8, #0x1
     d8c: d65f03c0     	ret

0000000000000d90 <__ZNKSt3__117__compressed_pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repES5_E5firstB8ue170006Ev>:
     d90: d10083ff     	sub	sp, sp, #32
     d94: a9017bfd     	stp	x29, x30, [sp, #16]
     d98: 910043fd     	add	x29, sp, #16
     d9c: f90007e0     	str	x0, [sp, #8]
     da0: f94007e0     	ldr	x0, [sp, #8]
     da4: 94000000     	bl	0xda4 <__ZNKSt3__117__compressed_pairINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repES5_E5firstB8ue170006Ev+0x14>
     da8: a9417bfd     	ldp	x29, x30, [sp, #16]
     dac: 910083ff     	add	sp, sp, #32
     db0: d65f03c0     	ret

0000000000000db4 <__ZNKSt3__122__compressed_pair_elemINS_12basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5__repELi0ELb0EE5__getB8ue170006Ev>:
     db4: d10043ff     	sub	sp, sp, #16
     db8: f90007e0     	str	x0, [sp, #8]
     dbc: f94007e0     	ldr	x0, [sp, #8]
     dc0: 910043ff     	add	sp, sp, #16
     dc4: d65f03c0     	ret

0000000000000dc8 <__ZNSt3__114pointer_traitsIPKcE10pointer_toB8ue170006ERS1_>:
     dc8: d10043ff     	sub	sp, sp, #16
     dcc: f90007e0     	str	x0, [sp, #8]
     dd0: f94007e0     	ldr	x0, [sp, #8]
     dd4: 910043ff     	add	sp, sp, #16
     dd8: d65f03c0     	ret

0000000000000ddc <__ZNSt3__119ostreambuf_iteratorIcNS_11char_traitsIcEEEC2B8ue170006ERNS_13basic_ostreamIcS2_EE>:
     ddc: d10103ff     	sub	sp, sp, #64
     de0: a9037bfd     	stp	x29, x30, [sp, #48]
     de4: 9100c3fd     	add	x29, sp, #48
     de8: f81f83a0     	stur	x0, [x29, #-8]
     dec: f81f03a1     	stur	x1, [x29, #-16]
     df0: f85f83a8     	ldur	x8, [x29, #-8]
     df4: f90003e8     	str	x8, [sp]
     df8: f85f03a8     	ldur	x8, [x29, #-16]
     dfc: f9400109     	ldr	x9, [x8]
     e00: f85e8129     	ldur	x9, [x9, #-24]
     e04: 8b090100     	add	x0, x8, x9
     e08: 94000000     	bl	0xe08 <__ZNSt3__119ostreambuf_iteratorIcNS_11char_traitsIcEEEC2B8ue170006ERNS_13basic_ostreamIcS2_EE+0x2c>
     e0c: f90007e0     	str	x0, [sp, #8]
     e10: 14000001     	b	0xe14 <__ZNSt3__119ostreambuf_iteratorIcNS_11char_traitsIcEEEC2B8ue170006ERNS_13basic_ostreamIcS2_EE+0x38>
     e14: f94003e0     	ldr	x0, [sp]
     e18: f94007e8     	ldr	x8, [sp, #8]
     e1c: f9000008     	str	x8, [x0]
     e20: a9437bfd     	ldp	x29, x30, [sp, #48]
     e24: 910103ff     	add	sp, sp, #64
     e28: d65f03c0     	ret
     e2c: f9000fe0     	str	x0, [sp, #24]
     e30: aa0103e8     	mov	x8, x1
     e34: b90017e8     	str	w8, [sp, #20]
     e38: 14000001     	b	0xe3c <__ZNSt3__119ostreambuf_iteratorIcNS_11char_traitsIcEEEC2B8ue170006ERNS_13basic_ostreamIcS2_EE+0x60>
     e3c: f9400fe0     	ldr	x0, [sp, #24]
     e40: 94000000     	bl	0xe40 <__ZNSt3__119ostreambuf_iteratorIcNS_11char_traitsIcEEEC2B8ue170006ERNS_13basic_ostreamIcS2_EE+0x64>

0000000000000e44 <__ZNKSt3__19basic_iosIcNS_11char_traitsIcEEE5rdbufB8ue170006Ev>:
     e44: d10083ff     	sub	sp, sp, #32
     e48: a9017bfd     	stp	x29, x30, [sp, #16]
     e4c: 910043fd     	add	x29, sp, #16
     e50: f90007e0     	str	x0, [sp, #8]
     e54: f94007e0     	ldr	x0, [sp, #8]
     e58: 94000000     	bl	0xe58 <__ZNKSt3__19basic_iosIcNS_11char_traitsIcEEE5rdbufB8ue170006Ev+0x14>
     e5c: a9417bfd     	ldp	x29, x30, [sp, #16]
     e60: 910083ff     	add	sp, sp, #32
     e64: d65f03c0     	ret

0000000000000e68 <__ZNKSt3__18ios_base5rdbufB8ue170006Ev>:
     e68: d10043ff     	sub	sp, sp, #16
     e6c: f90007e0     	str	x0, [sp, #8]
     e70: f94007e8     	ldr	x8, [sp, #8]
     e74: f9401500     	ldr	x0, [x8, #40]
     e78: 910043ff     	add	sp, sp, #16
     e7c: d65f03c0     	ret

0000000000000e80 <__ZNSt3__111char_traitsIcE11eq_int_typeB8ue170006Eii>:
     e80: d10043ff     	sub	sp, sp, #16
     e84: b9000fe0     	str	w0, [sp, #12]
     e88: b9000be1     	str	w1, [sp, #8]
     e8c: b9400fe8     	ldr	w8, [sp, #12]
     e90: b9400be9     	ldr	w9, [sp, #8]
     e94: 6b090108     	subs	w8, w8, w9
     e98: 1a9f17e8     	cset	w8, eq
     e9c: 12000100     	and	w0, w8, #0x1
     ea0: 910043ff     	add	sp, sp, #16
     ea4: d65f03c0     	ret

0000000000000ea8 <__ZNSt3__111char_traitsIcE3eofB8ue170006Ev>:
     ea8: 12800000     	mov	w0, #-1
     eac: d65f03c0     	ret

0000000000000eb0 <__ZNKSt3__19basic_iosIcNS_11char_traitsIcEEE5widenB8ue170006Ec>:
     eb0: d10143ff     	sub	sp, sp, #80
     eb4: a9047bfd     	stp	x29, x30, [sp, #64]
     eb8: 910103fd     	add	x29, sp, #64
     ebc: f81f83a0     	stur	x0, [x29, #-8]
     ec0: 381f73a1     	sturb	w1, [x29, #-9]
     ec4: f85f83a0     	ldur	x0, [x29, #-8]
     ec8: d10063a8     	sub	x8, x29, #24
     ecc: f90007e8     	str	x8, [sp, #8]
     ed0: 94000000     	bl	0xed0 <__ZNKSt3__19basic_iosIcNS_11char_traitsIcEEE5widenB8ue170006Ec+0x20>
     ed4: f94007e0     	ldr	x0, [sp, #8]
     ed8: 94000000     	bl	0xed8 <__ZNKSt3__19basic_iosIcNS_11char_traitsIcEEE5widenB8ue170006Ec+0x28>
     edc: f9000be0     	str	x0, [sp, #16]
     ee0: 14000001     	b	0xee4 <__ZNKSt3__19basic_iosIcNS_11char_traitsIcEEE5widenB8ue170006Ec+0x34>
     ee4: f9400be0     	ldr	x0, [sp, #16]
     ee8: 38df73a1     	ldursb	w1, [x29, #-9]
     eec: 94000000     	bl	0xeec <__ZNKSt3__19basic_iosIcNS_11char_traitsIcEEE5widenB8ue170006Ec+0x3c>
     ef0: b90007e0     	str	w0, [sp, #4]
     ef4: 14000001     	b	0xef8 <__ZNKSt3__19basic_iosIcNS_11char_traitsIcEEE5widenB8ue170006Ec+0x48>
     ef8: d10063a0     	sub	x0, x29, #24
     efc: 94000000     	bl	0xefc <__ZNKSt3__19basic_iosIcNS_11char_traitsIcEEE5widenB8ue170006Ec+0x4c>
     f00: b94007e8     	ldr	w8, [sp, #4]
     f04: 13001d00     	sxtb	w0, w8
     f08: a9447bfd     	ldp	x29, x30, [sp, #64]
     f0c: 910143ff     	add	sp, sp, #80
     f10: d65f03c0     	ret
     f14: f90013e0     	str	x0, [sp, #32]
     f18: aa0103e8     	mov	x8, x1
     f1c: b9001fe8     	str	w8, [sp, #28]
     f20: d10063a0     	sub	x0, x29, #24
     f24: 94000000     	bl	0xf24 <__ZNKSt3__19basic_iosIcNS_11char_traitsIcEEE5widenB8ue170006Ec+0x74>
     f28: 14000001     	b	0xf2c <__ZNKSt3__19basic_iosIcNS_11char_traitsIcEEE5widenB8ue170006Ec+0x7c>
     f2c: 14000001     	b	0xf30 <__ZNKSt3__19basic_iosIcNS_11char_traitsIcEEE5widenB8ue170006Ec+0x80>
     f30: f94013e0     	ldr	x0, [sp, #32]
     f34: 94000000     	bl	0xf34 <__ZNKSt3__19basic_iosIcNS_11char_traitsIcEEE5widenB8ue170006Ec+0x84>
     f38: 94000000     	bl	0xf38 <__ZNKSt3__19basic_iosIcNS_11char_traitsIcEEE5widenB8ue170006Ec+0x88>

0000000000000f3c <__ZNSt3__19use_facetB8ue170006INS_5ctypeIcEEEERKT_RKNS_6localeE>:
     f3c: d10083ff     	sub	sp, sp, #32
     f40: a9017bfd     	stp	x29, x30, [sp, #16]
     f44: 910043fd     	add	x29, sp, #16
     f48: f90007e0     	str	x0, [sp, #8]
     f4c: f94007e0     	ldr	x0, [sp, #8]
     f50: 90000001     	adrp	x1, 0x0 <__ZNSt3__19use_facetB8ue170006INS_5ctypeIcEEEERKT_RKNS_6localeE+0x14>
     f54: f9400021     	ldr	x1, [x1]
     f58: 94000000     	bl	0xf58 <__ZNSt3__19use_facetB8ue170006INS_5ctypeIcEEEERKT_RKNS_6localeE+0x1c>
     f5c: a9417bfd     	ldp	x29, x30, [sp, #16]
     f60: 910083ff     	add	sp, sp, #32
     f64: d65f03c0     	ret

0000000000000f68 <__ZNKSt3__15ctypeIcE5widenB8ue170006Ec>:
     f68: d10083ff     	sub	sp, sp, #32
     f6c: a9017bfd     	stp	x29, x30, [sp, #16]
     f70: 910043fd     	add	x29, sp, #16
     f74: f90007e0     	str	x0, [sp, #8]
     f78: 39001fe1     	strb	w1, [sp, #7]
     f7c: f94007e0     	ldr	x0, [sp, #8]
     f80: 39c01fe1     	ldrsb	w1, [sp, #7]
     f84: f9400008     	ldr	x8, [x0]
     f88: f9401d08     	ldr	x8, [x8, #56]
     f8c: d63f0100     	blr	x8
     f90: 13001c00     	sxtb	w0, w0
     f94: a9417bfd     	ldp	x29, x30, [sp, #16]
     f98: 910083ff     	add	sp, sp, #32
     f9c: d65f03c0     	ret

0000000000000fa0 <__ZNSt3__18ios_base8setstateB8ue170006Ej>:
     fa0: d10083ff     	sub	sp, sp, #32
     fa4: a9017bfd     	stp	x29, x30, [sp, #16]
     fa8: 910043fd     	add	x29, sp, #16
     fac: f90007e0     	str	x0, [sp, #8]
     fb0: b90007e1     	str	w1, [sp, #4]
     fb4: f94007e0     	ldr	x0, [sp, #8]
     fb8: b9402008     	ldr	w8, [x0, #32]
     fbc: b94007e9     	ldr	w9, [sp, #4]
     fc0: 2a090101     	orr	w1, w8, w9
     fc4: 94000000     	bl	0xfc4 <__ZNSt3__18ios_base8setstateB8ue170006Ej+0x24>
     fc8: a9417bfd     	ldp	x29, x30, [sp, #16]
     fcc: 910083ff     	add	sp, sp, #32
     fd0: d65f03c0     	ret

0000000000000fd4 <__ZNSt3__118__constexpr_strlenB8ue170006EPKc>:
     fd4: d10083ff     	sub	sp, sp, #32
     fd8: a9017bfd     	stp	x29, x30, [sp, #16]
     fdc: 910043fd     	add	x29, sp, #16
     fe0: f90007e0     	str	x0, [sp, #8]
     fe4: f94007e0     	ldr	x0, [sp, #8]
     fe8: 94000000     	bl	0xfe8 <__ZNSt3__118__constexpr_strlenB8ue170006EPKc+0x14>
     fec: a9417bfd     	ldp	x29, x30, [sp, #16]
     ff0: 910083ff     	add	sp, sp, #32
     ff4: d65f03c0     	ret

0000000000000ff8 <__ZNKSt3__113basic_istreamIcNS_11char_traitsIcEEE6sentrycvbB8ue170006Ev>:
     ff8: d10043ff     	sub	sp, sp, #16
     ffc: f90007e0     	str	x0, [sp, #8]
    1000: f94007e8     	ldr	x8, [sp, #8]
    1004: 39400108     	ldrb	w8, [x8]
    1008: 12000100     	and	w0, w8, #0x1
    100c: 910043ff     	add	sp, sp, #16
    1010: d65f03c0     	ret

0000000000001014 <__ZNSt3__115basic_streambufIcNS_11char_traitsIcEEE6sbumpcB8ue170006Ev>:
    1014: d100c3ff     	sub	sp, sp, #48
    1018: a9027bfd     	stp	x29, x30, [sp, #32]
    101c: 910083fd     	add	x29, sp, #32
    1020: f9000be0     	str	x0, [sp, #16]
    1024: f9400be9     	ldr	x9, [sp, #16]
    1028: f90007e9     	str	x9, [sp, #8]
    102c: f9400d28     	ldr	x8, [x9, #24]
    1030: f9401129     	ldr	x9, [x9, #32]
    1034: eb090108     	subs	x8, x8, x9
    1038: 1a9f07e8     	cset	w8, ne
    103c: 37000108     	tbnz	w8, #0, 0x105c <__ZNSt3__115basic_streambufIcNS_11char_traitsIcEEE6sbumpcB8ue170006Ev+0x48>
    1040: 14000001     	b	0x1044 <__ZNSt3__115basic_streambufIcNS_11char_traitsIcEEE6sbumpcB8ue170006Ev+0x30>
    1044: f94007e0     	ldr	x0, [sp, #8]
    1048: f9400008     	ldr	x8, [x0]
    104c: f9402908     	ldr	x8, [x8, #80]
    1050: d63f0100     	blr	x8
    1054: b81fc3a0     	stur	w0, [x29, #-4]
    1058: 14000009     	b	0x107c <__ZNSt3__115basic_streambufIcNS_11char_traitsIcEEE6sbumpcB8ue170006Ev+0x68>
    105c: f94007ea     	ldr	x10, [sp, #8]
    1060: f9400d48     	ldr	x8, [x10, #24]
    1064: 91000509     	add	x9, x8, #1
    1068: f9000d49     	str	x9, [x10, #24]
    106c: 39c00100     	ldrsb	w0, [x8]
    1070: 94000000     	bl	0x1070 <__ZNSt3__115basic_streambufIcNS_11char_traitsIcEEE6sbumpcB8ue170006Ev+0x5c>
    1074: b81fc3a0     	stur	w0, [x29, #-4]
    1078: 14000001     	b	0x107c <__ZNSt3__115basic_streambufIcNS_11char_traitsIcEEE6sbumpcB8ue170006Ev+0x68>
    107c: b85fc3a0     	ldur	w0, [x29, #-4]
    1080: a9427bfd     	ldp	x29, x30, [sp, #32]
    1084: 9100c3ff     	add	sp, sp, #48
    1088: d65f03c0     	ret

000000000000108c <__ZNSt3__111char_traitsIcE12to_char_typeB8ue170006Ei>:
    108c: d10043ff     	sub	sp, sp, #16
    1090: b9000fe0     	str	w0, [sp, #12]
    1094: b9400fe8     	ldr	w8, [sp, #12]
    1098: 13001d00     	sxtb	w0, w8
    109c: 910043ff     	add	sp, sp, #16
    10a0: d65f03c0     	ret

00000000000010a4 <__ZNSt3__18ios_base18__setstate_nothrowB8ue170006Ej>:
    10a4: d10083ff     	sub	sp, sp, #32
    10a8: f9000fe0     	str	x0, [sp, #24]
    10ac: b90017e1     	str	w1, [sp, #20]
    10b0: f9400fe8     	ldr	x8, [sp, #24]
    10b4: f90007e8     	str	x8, [sp, #8]
    10b8: f9401508     	ldr	x8, [x8, #40]
    10bc: f1000108     	subs	x8, x8, #0
    10c0: 1a9f17e8     	cset	w8, eq
    10c4: 37000108     	tbnz	w8, #0, 0x10e4 <__ZNSt3__18ios_base18__setstate_nothrowB8ue170006Ej+0x40>
    10c8: 14000001     	b	0x10cc <__ZNSt3__18ios_base18__setstate_nothrowB8ue170006Ej+0x28>
    10cc: f94007e9     	ldr	x9, [sp, #8]
    10d0: b94017ea     	ldr	w10, [sp, #20]
    10d4: b9402128     	ldr	w8, [x9, #32]
    10d8: 2a0a0108     	orr	w8, w8, w10
    10dc: b9002128     	str	w8, [x9, #32]
    10e0: 14000008     	b	0x1100 <__ZNSt3__18ios_base18__setstate_nothrowB8ue170006Ej+0x5c>
    10e4: f94007e9     	ldr	x9, [sp, #8]
    10e8: b94017e8     	ldr	w8, [sp, #20]
    10ec: 3200010a     	orr	w10, w8, #0x1
    10f0: b9402128     	ldr	w8, [x9, #32]
    10f4: 2a0a0108     	orr	w8, w8, w10
    10f8: b9002128     	str	w8, [x9, #32]
    10fc: 14000001     	b	0x1100 <__ZNSt3__18ios_base18__setstate_nothrowB8ue170006Ej+0x5c>
    1100: 910083ff     	add	sp, sp, #32
    1104: d65f03c0     	ret

0000000000001108 <__ZNKSt3__19basic_iosIcNS_11char_traitsIcEEE10exceptionsB8ue170006Ev>:
    1108: d10083ff     	sub	sp, sp, #32
    110c: a9017bfd     	stp	x29, x30, [sp, #16]
    1110: 910043fd     	add	x29, sp, #16
    1114: f90007e0     	str	x0, [sp, #8]
    1118: f94007e0     	ldr	x0, [sp, #8]
    111c: 94000000     	bl	0x111c <__ZNKSt3__19basic_iosIcNS_11char_traitsIcEEE10exceptionsB8ue170006Ev+0x14>
    1120: a9417bfd     	ldp	x29, x30, [sp, #16]
    1124: 910083ff     	add	sp, sp, #32
    1128: d65f03c0     	ret

000000000000112c <__ZNSt3__111char_traitsIcE11to_int_typeB8ue170006Ec>:
    112c: d10043ff     	sub	sp, sp, #16
    1130: 39003fe0     	strb	w0, [sp, #15]
    1134: 39403fe0     	ldrb	w0, [sp, #15]
    1138: 910043ff     	add	sp, sp, #16
    113c: d65f03c0     	ret

0000000000001140 <__ZNKSt3__18ios_base10exceptionsB8ue170006Ev>:
    1140: d10043ff     	sub	sp, sp, #16
    1144: f90007e0     	str	x0, [sp, #8]
    1148: f94007e8     	ldr	x8, [sp, #8]
    114c: b9402500     	ldr	w0, [x8, #36]
    1150: 910043ff     	add	sp, sp, #16
    1154: d65f03c0     	ret
