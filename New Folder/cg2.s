	.file	"cg2.c"
# GNU C23 (Ubuntu 15.2.0-16ubuntu1) version 15.2.0 (x86_64-linux-gnu)
#	compiled by GNU C version 15.2.0, GMP version 6.3.0, MPFR version 4.2.2, MPC version 1.3.1, isl version isl-0.27-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed: -mtune=generic -march=x86-64 -O0 -fasynchronous-unwind-tables -fstack-protector-strong -fstack-clash-protection -fcf-protection -fzero-init-padding-bits=all
	.text
	.globl	startX
	.bss
	.align 4
	.type	startX, @object
	.size	startX, 4
startX:
	.zero	4
	.globl	startY
	.align 4
	.type	startY, @object
	.size	startY, 4
startY:
	.zero	4
	.globl	endX
	.align 4
	.type	endX, @object
	.size	endX, 4
endX:
	.zero	4
	.globl	endY
	.align 4
	.type	endY, @object
	.size	endY, 4
endY:
	.zero	4
	.text
	.globl	display
	.type	display, @function
display:
.LFB6:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$32, %rsp	#,
# /home/kanak/Desktop/dwm/New Folder/cg2.c:10:     glClear(GL_COLOR_BUFFER_BIT);
	movl	$16384, %edi	#,
	call	glClear@PLT	#
# /home/kanak/Desktop/dwm/New Folder/cg2.c:11:     glColor3f(1.0f, 1.0f, 1.0f);
	movss	.LC0(%rip), %xmm2	#,
	movss	.LC0(%rip), %xmm1	#,
	movl	.LC0(%rip), %eax	#, tmp107
	movd	%eax, %xmm0	# tmp107,
	call	glColor3f@PLT	#
# /home/kanak/Desktop/dwm/New Folder/cg2.c:12:     glPointSize(3.0f);
	movl	.LC1(%rip), %eax	#, tmp108
	movd	%eax, %xmm0	# tmp108,
	call	glPointSize@PLT	#
# /home/kanak/Desktop/dwm/New Folder/cg2.c:14:     float dx = endX - startX;
	movss	endX(%rip), %xmm0	# endX, endX.0_1
	movss	startX(%rip), %xmm1	# startX, startX.1_2
# /home/kanak/Desktop/dwm/New Folder/cg2.c:14:     float dx = endX - startX;
	subss	%xmm1, %xmm0	# startX.1_2, dx_19
	movss	%xmm0, -20(%rbp)	# dx_19, dx
# /home/kanak/Desktop/dwm/New Folder/cg2.c:15:     float dy = endY - startY;
	movss	endY(%rip), %xmm0	# endY, endY.2_3
	movss	startY(%rip), %xmm1	# startY, startY.3_4
# /home/kanak/Desktop/dwm/New Folder/cg2.c:15:     float dy = endY - startY;
	subss	%xmm1, %xmm0	# startY.3_4, dy_20
	movss	%xmm0, -16(%rbp)	# dy_20, dy
# /home/kanak/Desktop/dwm/New Folder/cg2.c:16:     float steps = fmaxf(fabsf(dx), fabsf(dy));
	movss	-16(%rbp), %xmm0	# dy, tmp111
	movss	.LC2(%rip), %xmm1	#, tmp112
	andps	%xmm1, %xmm0	# tmp112, tmp111
	movd	%xmm0, %eax	# tmp111, _5
	movss	-20(%rbp), %xmm0	# dx, tmp113
	movss	.LC2(%rip), %xmm1	#, tmp114
	andps	%xmm1, %xmm0	# tmp114, _6
	movaps	%xmm0, %xmm1	# _6,
	movd	%eax, %xmm0	# _5,
	call	fmaxf@PLT	#
	movd	%xmm0, %eax	#, tmp115
	movl	%eax, -12(%rbp)	# tmp115, steps
# /home/kanak/Desktop/dwm/New Folder/cg2.c:18:     glBegin(GL_POINTS);
	movl	$0, %edi	#,
	call	glBegin@PLT	#
# /home/kanak/Desktop/dwm/New Folder/cg2.c:20:     if (steps == 0)
	pxor	%xmm0, %xmm0	# tmp116
	ucomiss	-12(%rbp), %xmm0	# steps, tmp116
	jp	.L2	#,
	pxor	%xmm0, %xmm0	# tmp117
	ucomiss	-12(%rbp), %xmm0	# steps, tmp117
	jne	.L2	#,
# /home/kanak/Desktop/dwm/New Folder/cg2.c:22:         glVertex2f(startX, startY);
	movss	startY(%rip), %xmm0	# startY, startY.4_7
	movl	startX(%rip), %eax	# startX, startX.5_8
	movaps	%xmm0, %xmm1	# startY.4_7,
	movd	%eax, %xmm0	# startX.5_8,
	call	glVertex2f@PLT	#
	jmp	.L4	#
.L2:
# /home/kanak/Desktop/dwm/New Folder/cg2.c:26:         float x = startX;
	movss	startX(%rip), %xmm0	# startX, tmp118
	movss	%xmm0, -32(%rbp)	# tmp118, x
# /home/kanak/Desktop/dwm/New Folder/cg2.c:27:         float y = startY;
	movss	startY(%rip), %xmm0	# startY, tmp119
	movss	%xmm0, -28(%rbp)	# tmp119, y
# /home/kanak/Desktop/dwm/New Folder/cg2.c:28:         float xinc = dx / steps;
	movss	-20(%rbp), %xmm0	# dx, tmp121
	divss	-12(%rbp), %xmm0	# steps, xinc_25
	movss	%xmm0, -8(%rbp)	# xinc_25, xinc
# /home/kanak/Desktop/dwm/New Folder/cg2.c:29:         float yinc = dy / steps;
	movss	-16(%rbp), %xmm0	# dy, tmp123
	divss	-12(%rbp), %xmm0	# steps, yinc_26
	movss	%xmm0, -4(%rbp)	# yinc_26, yinc
# /home/kanak/Desktop/dwm/New Folder/cg2.c:31:         for (int i = 0; i <= (int)steps; i++)
	movl	$0, -24(%rbp)	#, i
# /home/kanak/Desktop/dwm/New Folder/cg2.c:31:         for (int i = 0; i <= (int)steps; i++)
	jmp	.L5	#
.L6:
# /home/kanak/Desktop/dwm/New Folder/cg2.c:33:             glVertex2f(x, y);
	movss	-28(%rbp), %xmm0	# y, tmp124
	movl	-32(%rbp), %eax	# x, tmp125
	movaps	%xmm0, %xmm1	# tmp124,
	movd	%eax, %xmm0	# tmp125,
	call	glVertex2f@PLT	#
# /home/kanak/Desktop/dwm/New Folder/cg2.c:34:             x += xinc;
	movss	-32(%rbp), %xmm0	# x, tmp127
	addss	-8(%rbp), %xmm0	# xinc, x_29
	movss	%xmm0, -32(%rbp)	# x_29, x
# /home/kanak/Desktop/dwm/New Folder/cg2.c:35:             y += yinc;
	movss	-28(%rbp), %xmm0	# y, tmp129
	addss	-4(%rbp), %xmm0	# yinc, y_30
	movss	%xmm0, -28(%rbp)	# y_30, y
# /home/kanak/Desktop/dwm/New Folder/cg2.c:31:         for (int i = 0; i <= (int)steps; i++)
	addl	$1, -24(%rbp)	#, i
.L5:
# /home/kanak/Desktop/dwm/New Folder/cg2.c:31:         for (int i = 0; i <= (int)steps; i++)
	movss	-12(%rbp), %xmm0	# steps, tmp130
	cvttss2sil	%xmm0, %eax	# tmp130, _9
# /home/kanak/Desktop/dwm/New Folder/cg2.c:31:         for (int i = 0; i <= (int)steps; i++)
	cmpl	%eax, -24(%rbp)	# _9, i
	jle	.L6	#,
.L4:
# /home/kanak/Desktop/dwm/New Folder/cg2.c:39:     glEnd();
	call	glEnd@PLT	#
# /home/kanak/Desktop/dwm/New Folder/cg2.c:40:     glFlush();
	call	glFlush@PLT	#
# /home/kanak/Desktop/dwm/New Folder/cg2.c:41: }
	nop	
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE6:
	.size	display, .-display
	.globl	reshape
	.type	reshape, @function
reshape:
.LFB7:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
	movl	%edi, -4(%rbp)	# width, width
	movl	%esi, -8(%rbp)	# height, height
# /home/kanak/Desktop/dwm/New Folder/cg2.c:45:     glViewport(0, 0, width, height);
	movl	-8(%rbp), %edx	# height, tmp98
	movl	-4(%rbp), %eax	# width, tmp99
	movl	%edx, %ecx	# tmp98,
	movl	%eax, %edx	# tmp99,
	movl	$0, %esi	#,
	movl	$0, %edi	#,
	call	glViewport@PLT	#
# /home/kanak/Desktop/dwm/New Folder/cg2.c:47:     glMatrixMode(GL_PROJECTION);
	movl	$5889, %edi	#,
	call	glMatrixMode@PLT	#
# /home/kanak/Desktop/dwm/New Folder/cg2.c:48:     glLoadIdentity();
	call	glLoadIdentity@PLT	#
# /home/kanak/Desktop/dwm/New Folder/cg2.c:49:     glOrtho(0, 800, 0, 600, -1, 1);
	movsd	.LC4(%rip), %xmm3	#, tmp100
	movsd	.LC5(%rip), %xmm2	#, tmp101
	movsd	.LC6(%rip), %xmm1	#, tmp102
	movsd	.LC7(%rip), %xmm0	#, tmp103
	movapd	%xmm3, %xmm5	# tmp100,
	movapd	%xmm2, %xmm4	# tmp101,
	movapd	%xmm1, %xmm3	# tmp102,
	pxor	%xmm2, %xmm2	#
	movapd	%xmm0, %xmm1	# tmp103,
	movq	.LC8(%rip), %rax	#, tmp104
	movq	%rax, %xmm0	# tmp104,
	call	glOrtho@PLT	#
# /home/kanak/Desktop/dwm/New Folder/cg2.c:51:     glMatrixMode(GL_MODELVIEW);
	movl	$5888, %edi	#,
	call	glMatrixMode@PLT	#
# /home/kanak/Desktop/dwm/New Folder/cg2.c:52:     glLoadIdentity();
	call	glLoadIdentity@PLT	#
# /home/kanak/Desktop/dwm/New Folder/cg2.c:53: }
	nop	
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE7:
	.size	reshape, .-reshape
	.section	.rodata
	.align 8
.LC9:
	.string	"Enter the start coordinates (x y): "
.LC10:
	.string	"%f %f"
	.align 8
.LC11:
	.string	"Enter the end coordinates (x y): "
.LC12:
	.string	"DDA Line Drawing Algorithm"
	.text
	.globl	main
	.type	main, @function
main:
.LFB8:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$16, %rsp	#,
	movl	%edi, -4(%rbp)	# argc, argc
	movq	%rsi, -16(%rbp)	# argv, argv
# /home/kanak/Desktop/dwm/New Folder/cg2.c:57:     printf("Enter the start coordinates (x y): ");
	leaq	.LC9(%rip), %rax	#, tmp100
	movq	%rax, %rdi	# tmp100,
	movl	$0, %eax	#,
	call	printf@PLT	#
# /home/kanak/Desktop/dwm/New Folder/cg2.c:58:     scanf("%f %f", &startX, &startY);
	leaq	startY(%rip), %rdx	#, tmp101
	leaq	startX(%rip), %rcx	#, tmp102
	leaq	.LC10(%rip), %rax	#, tmp103
	movq	%rcx, %rsi	# tmp102,
	movq	%rax, %rdi	# tmp103,
	movl	$0, %eax	#,
	call	__isoc23_scanf@PLT	#
# /home/kanak/Desktop/dwm/New Folder/cg2.c:60:     printf("Enter the end coordinates (x y): ");
	leaq	.LC11(%rip), %rax	#, tmp104
	movq	%rax, %rdi	# tmp104,
	movl	$0, %eax	#,
	call	printf@PLT	#
# /home/kanak/Desktop/dwm/New Folder/cg2.c:61:     scanf("%f %f", &endX, &endY);
	leaq	endY(%rip), %rdx	#, tmp105
	leaq	endX(%rip), %rcx	#, tmp106
	leaq	.LC10(%rip), %rax	#, tmp107
	movq	%rcx, %rsi	# tmp106,
	movq	%rax, %rdi	# tmp107,
	movl	$0, %eax	#,
	call	__isoc23_scanf@PLT	#
# /home/kanak/Desktop/dwm/New Folder/cg2.c:63:     glutInit(&argc, argv);
	movq	-16(%rbp), %rdx	# argv, tmp108
	leaq	-4(%rbp), %rax	#, tmp109
	movq	%rdx, %rsi	# tmp108,
	movq	%rax, %rdi	# tmp109,
	call	glutInit@PLT	#
# /home/kanak/Desktop/dwm/New Folder/cg2.c:64:     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	movl	$0, %edi	#,
	call	glutInitDisplayMode@PLT	#
# /home/kanak/Desktop/dwm/New Folder/cg2.c:65:     glutInitWindowSize(800, 600);
	movl	$600, %esi	#,
	movl	$800, %edi	#,
	call	glutInitWindowSize@PLT	#
# /home/kanak/Desktop/dwm/New Folder/cg2.c:66:     glutCreateWindow("DDA Line Drawing Algorithm");
	leaq	.LC12(%rip), %rax	#, tmp110
	movq	%rax, %rdi	# tmp110,
	call	glutCreateWindow@PLT	#
# /home/kanak/Desktop/dwm/New Folder/cg2.c:68:     glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	movss	.LC0(%rip), %xmm3	#,
	pxor	%xmm2, %xmm2	#
	pxor	%xmm1, %xmm1	#
	movl	.LC3(%rip), %eax	#, tmp111
	movd	%eax, %xmm0	# tmp111,
	call	glClearColor@PLT	#
# /home/kanak/Desktop/dwm/New Folder/cg2.c:70:     glutDisplayFunc(display);
	leaq	display(%rip), %rax	#, tmp112
	movq	%rax, %rdi	# tmp112,
	call	glutDisplayFunc@PLT	#
# /home/kanak/Desktop/dwm/New Folder/cg2.c:71:     glutReshapeFunc(reshape);
	leaq	reshape(%rip), %rax	#, tmp113
	movq	%rax, %rdi	# tmp113,
	call	glutReshapeFunc@PLT	#
# /home/kanak/Desktop/dwm/New Folder/cg2.c:73:     glutMainLoop();
	call	glutMainLoop@PLT	#
# /home/kanak/Desktop/dwm/New Folder/cg2.c:75:     return 0;
	movl	$0, %eax	#, _15
# /home/kanak/Desktop/dwm/New Folder/cg2.c:76: }
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE8:
	.size	main, .-main
	.section	.rodata
	.align 4
.LC0:
	.long	1065353216
	.align 4
.LC1:
	.long	1077936128
	.align 16
.LC2:
	.long	2147483647
	.long	0
	.long	0
	.long	0
	.align 4
.LC3:
	.long	0
	.align 8
.LC4:
	.long	0
	.long	1072693248
	.align 8
.LC5:
	.long	0
	.long	-1074790400
	.align 8
.LC6:
	.long	0
	.long	1082310656
	.align 8
.LC7:
	.long	0
	.long	1082720256
	.align 8
.LC8:
	.long	0
	.long	0
	.ident	"GCC: (Ubuntu 15.2.0-16ubuntu1) 15.2.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
