	.file	"main.c"
	.text
	.section	.rodata
.LC2:
	.string	"%d"
	.align 8
.LC3:
	.string	"You can choose between 1 and 6!\nYour choice: "
.LC4:
	.string	"Title: %25s\t"
.LC5:
	.string	"Author: %25s\t"
.LC6:
	.string	"Numbr of pages: %5d\t"
.LC7:
	.string	"Price: %10.2lf\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$3280, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, %edi
	call	time@PLT
	movl	%eax, %edi
	call	srand@PLT
	movl	$0, -3276(%rbp)
	jmp	.L2
.L3:
	leaq	-3264(%rbp), %rcx
	movl	-3276(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	leaq	0(,%rax,8), %rdx
	addq	%rdx, %rax
	salq	$3, %rax
	addq	%rcx, %rax
	movl	$20, %edx
	movl	$10, %esi
	movq	%rax, %rdi
	call	randString@PLT
	movw	$32, -22(%rbp)
	leaq	-3264(%rbp), %rcx
	movl	-3276(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	leaq	0(,%rax,8), %rdx
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$96, %rax
	addq	%rcx, %rax
	addq	$5, %rax
	movl	$10, %edx
	movl	$3, %esi
	movq	%rax, %rdi
	call	randString@PLT
	leaq	-20(%rbp), %rax
	movl	$10, %edx
	movl	$3, %esi
	movq	%rax, %rdi
	call	randString@PLT
	leaq	-3264(%rbp), %rcx
	movl	-3276(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	leaq	0(,%rax,8), %rdx
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$96, %rax
	addq	%rcx, %rax
	leaq	5(%rax), %rdx
	leaq	-22(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	strcat@PLT
	leaq	-3264(%rbp), %rcx
	movl	-3276(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	leaq	0(,%rax,8), %rdx
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$96, %rax
	addq	%rcx, %rax
	leaq	5(%rax), %rdx
	leaq	-20(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	strcat@PLT
	movl	$1000, %esi
	movl	$10, %edi
	call	randInt@PLT
	movl	%eax, %ecx
	movl	-3276(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	leaq	0(,%rax,8), %rdx
	addq	%rdx, %rax
	salq	$3, %rax
	addq	%rbp, %rax
	subq	$3062, %rax
	movw	%cx, (%rax)
	movsd	.LC0(%rip), %xmm0
	movq	.LC1(%rip), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, %xmm0
	call	randReal@PLT
	movq	%xmm0, %rdx
	movl	-3276(%rbp), %eax
	movslq	%eax, %rcx
	movq	%rcx, %rax
	addq	%rax, %rax
	addq	%rcx, %rax
	leaq	0(,%rax,8), %rcx
	addq	%rcx, %rax
	salq	$3, %rax
	addq	%rbp, %rax
	subq	$3056, %rax
	movq	%rdx, (%rax)
	addl	$1, -3276(%rbp)
.L2:
	cmpl	$14, -3276(%rbp)
	jle	.L3
	movl	$0, -3280(%rbp)
	movl	$0, -3272(%rbp)
	leaq	-3280(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	%eax, -3272(%rbp)
	nop
.L4:
	call	getchar@PLT
	cmpl	$10, %eax
	jne	.L4
	jmp	.L5
.L7:
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-3280(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	%eax, -3272(%rbp)
	nop
.L6:
	call	getchar@PLT
	cmpl	$10, %eax
	jne	.L6
.L5:
	cmpl	$0, -3272(%rbp)
	je	.L7
	movl	-3280(%rbp), %eax
	movl	%eax, %edi
	call	getComparator@PLT
	movq	%rax, %rdx
	leaq	-3264(%rbp), %rax
	movq	%rdx, %rcx
	movl	$216, %edx
	movl	$15, %esi
	movq	%rax, %rdi
	call	qsort@PLT
	movl	$0, -3268(%rbp)
	jmp	.L8
.L9:
	leaq	-3264(%rbp), %rcx
	movl	-3268(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	leaq	0(,%rax,8), %rdx
	addq	%rdx, %rax
	salq	$3, %rax
	addq	%rcx, %rax
	movq	%rax, %rsi
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-3264(%rbp), %rcx
	movl	-3268(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	leaq	0(,%rax,8), %rdx
	addq	%rdx, %rax
	salq	$3, %rax
	addq	$96, %rax
	addq	%rcx, %rax
	addq	$5, %rax
	movq	%rax, %rsi
	leaq	.LC5(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-3268(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	leaq	0(,%rax,8), %rdx
	addq	%rdx, %rax
	salq	$3, %rax
	addq	%rbp, %rax
	subq	$3062, %rax
	movzwl	(%rax), %eax
	movzwl	%ax, %eax
	movl	%eax, %esi
	leaq	.LC6(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-3268(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	addq	%rax, %rax
	addq	%rdx, %rax
	leaq	0(,%rax,8), %rdx
	addq	%rdx, %rax
	salq	$3, %rax
	addq	%rbp, %rax
	subq	$3056, %rax
	movq	(%rax), %rax
	movq	%rax, %xmm0
	leaq	.LC7(%rip), %rax
	movq	%rax, %rdi
	movl	$1, %eax
	call	printf@PLT
	addl	$1, -3268(%rbp)
.L8:
	cmpl	$9, -3268(%rbp)
	jle	.L9
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L11
	call	__stack_chk_fail@PLT
.L11:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC0:
	.long	0
	.long	1079574528
	.align 8
.LC1:
	.long	0
	.long	1073741824
	.ident	"GCC: (Ubuntu 11.3.0-1ubuntu1~22.04.1) 11.3.0"
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
