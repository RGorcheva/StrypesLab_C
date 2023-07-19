	.file	"main.c"
	.text
	.section	.rodata
	.align 8
.LC2:
	.string	"Choose between 1 and 4!\nYour choice: "
.LC3:
	.string	"%d"
	.align 8
.LC4:
	.string	"Wrong choice!\nYou must choose between 1 and 4!\n"
.LC5:
	.string	"%5.2lf\n"
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
	subq	$144, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, %edi
	call	time@PLT
	movl	%eax, %edi
	call	srand@PLT
	movq	$0, -96(%rbp)
	movq	$0, -88(%rbp)
	movq	$0, -80(%rbp)
	movq	$0, -72(%rbp)
	movq	$0, -64(%rbp)
	movq	$0, -56(%rbp)
	movq	$0, -48(%rbp)
	movq	$0, -40(%rbp)
	movq	$0, -32(%rbp)
	movq	$0, -24(%rbp)
	movq	comparator1@GOTPCREL(%rip), %rax
	movq	%rax, -128(%rbp)
	movq	comparator2@GOTPCREL(%rip), %rax
	movq	%rax, -120(%rbp)
	movq	comparator3@GOTPCREL(%rip), %rax
	movq	%rax, -112(%rbp)
	movq	comparator4@GOTPCREL(%rip), %rax
	movq	%rax, -104(%rbp)
	movl	$0, -140(%rbp)
	jmp	.L2
.L3:
	movsd	.LC0(%rip), %xmm0
	movq	.LC1(%rip), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, %xmm0
	call	randReal@PLT
	movq	%xmm0, %rax
	movl	-140(%rbp), %edx
	movslq	%edx, %rdx
	movq	%rax, -96(%rbp,%rdx,8)
	addl	$1, -140(%rbp)
.L2:
	cmpl	$9, -140(%rbp)
	jle	.L3
	movl	$0, -144(%rbp)
	movl	$0, -132(%rbp)
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-144(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	%eax, -132(%rbp)
	cmpl	$0, -132(%rbp)
	je	.L4
	movl	-144(%rbp), %eax
	testl	%eax, %eax
	jle	.L4
	movl	-144(%rbp), %eax
	cmpl	$4, %eax
	jle	.L5
.L4:
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$47, %edx
	movl	$1, %esi
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	call	fwrite@PLT
	movl	$1, %edi
	call	exit@PLT
.L5:
	movl	-144(%rbp), %eax
	subl	$1, %eax
	cltq
	movq	-128(%rbp,%rax,8), %rdx
	leaq	-96(%rbp), %rax
	movq	%rdx, %rcx
	movl	$8, %edx
	movl	$10, %esi
	movq	%rax, %rdi
	call	qsort@PLT
	movl	$0, -136(%rbp)
	jmp	.L6
.L7:
	movl	-136(%rbp), %eax
	cltq
	movq	-96(%rbp,%rax,8), %rax
	movq	%rax, %xmm0
	leaq	.LC5(%rip), %rax
	movq	%rax, %rdi
	movl	$1, %eax
	call	printf@PLT
	addl	$1, -136(%rbp)
.L6:
	cmpl	$9, -136(%rbp)
	jle	.L7
	movl	$0, %edi
	call	exit@PLT
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC0:
	.long	0
	.long	1077149696
	.align 8
.LC1:
	.long	0
	.long	-1071382528
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
