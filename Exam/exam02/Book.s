	.file	"Book.c"
	.text
	.globl	randInt
	.type	randInt, @function
randInt:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	call	rand@PLT
	movl	-8(%rbp), %edx
	subl	-4(%rbp), %edx
	leal	1(%rdx), %ecx
	cltd
	idivl	%ecx
	movl	-4(%rbp), %eax
	addl	%edx, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	randInt, .-randInt
	.globl	randReal
	.type	randReal, @function
randReal:
.LFB7:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movsd	%xmm0, -8(%rbp)
	movsd	%xmm1, -16(%rbp)
	call	rand@PLT
	pxor	%xmm0, %xmm0
	cvtsi2sdl	%eax, %xmm0
	movsd	.LC0(%rip), %xmm2
	movapd	%xmm0, %xmm1
	divsd	%xmm2, %xmm1
	movsd	-16(%rbp), %xmm0
	subsd	-8(%rbp), %xmm0
	mulsd	%xmm1, %xmm0
	addsd	-8(%rbp), %xmm0
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	randReal, .-randReal
	.globl	randSym
	.type	randSym, @function
randSym:
.LFB8:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	cmpl	$0, -4(%rbp)
	je	.L6
	call	rand@PLT
	movslq	%eax, %rdx
	imulq	$1321528399, %rdx, %rdx
	shrq	$32, %rdx
	sarl	$3, %edx
	movl	%eax, %ecx
	sarl	$31, %ecx
	subl	%ecx, %edx
	imull	$26, %edx, %ecx
	subl	%ecx, %eax
	movl	%eax, %edx
	movl	%edx, %eax
	addl	$65, %eax
	jmp	.L7
.L6:
	call	rand@PLT
	movslq	%eax, %rdx
	imulq	$1321528399, %rdx, %rdx
	shrq	$32, %rdx
	sarl	$3, %edx
	movl	%eax, %ecx
	sarl	$31, %ecx
	subl	%ecx, %edx
	imull	$26, %edx, %ecx
	subl	%ecx, %eax
	movl	%eax, %edx
	movl	%edx, %eax
	addl	$97, %eax
.L7:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	randSym, .-randSym
	.globl	randString
	.type	randString, @function
randString:
.LFB9:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -40(%rbp)
	movl	%esi, -44(%rbp)
	movl	%edx, -48(%rbp)
	movl	$1, %edi
	call	randSym
	movq	-40(%rbp), %rdx
	movb	%al, (%rdx)
	movl	-48(%rbp), %eax
	leal	1(%rax), %edx
	movl	-44(%rbp), %eax
	addl	$1, %eax
	movl	%edx, %esi
	movl	%eax, %edi
	call	randInt
	movl	%eax, -20(%rbp)
	movl	$1, -24(%rbp)
	jmp	.L9
.L10:
	movl	-24(%rbp), %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	leaq	(%rdx,%rax), %rbx
	movl	$0, %edi
	call	randSym
	movb	%al, (%rbx)
	addl	$1, -24(%rbp)
.L9:
	movl	-24(%rbp), %eax
	cmpl	-20(%rbp), %eax
	jl	.L10
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movb	$0, (%rax)
	movq	-40(%rbp), %rax
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	randString, .-randString
	.globl	titleAcs
	.type	titleAcs, @function
titleAcs:
.LFB10:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcmp@PLT
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	titleAcs, .-titleAcs
	.globl	titleDecs
	.type	titleDecs, @function
titleDecs:
.LFB11:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	strcmp@PLT
	negl	%eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	titleDecs, .-titleDecs
	.globl	pagesAcs
	.type	pagesAcs, @function
pagesAcs:
.LFB12:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movzwl	202(%rax), %eax
	movzwl	%ax, %edx
	movq	-16(%rbp), %rax
	movzwl	202(%rax), %eax
	movzwl	%ax, %ecx
	movl	%edx, %eax
	subl	%ecx, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE12:
	.size	pagesAcs, .-pagesAcs
	.globl	pagesDecs
	.type	pagesDecs, @function
pagesDecs:
.LFB13:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rax
	movzwl	202(%rax), %eax
	movzwl	%ax, %edx
	movq	-8(%rbp), %rax
	movzwl	202(%rax), %eax
	movzwl	%ax, %ecx
	movl	%edx, %eax
	subl	%ecx, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE13:
	.size	pagesDecs, .-pagesDecs
	.globl	priceAcs
	.type	priceAcs, @function
priceAcs:
.LFB14:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movsd	208(%rax), %xmm0
	movq	-16(%rbp), %rax
	movsd	208(%rax), %xmm1
	subsd	%xmm1, %xmm0
	movq	.LC1(%rip), %xmm1
	andpd	%xmm0, %xmm1
	movsd	.LC2(%rip), %xmm0
	comisd	%xmm1, %xmm0
	jbe	.L28
	movl	$0, %eax
	jmp	.L23
.L28:
	movq	-8(%rbp), %rax
	movsd	208(%rax), %xmm0
	movq	-16(%rbp), %rax
	movsd	208(%rax), %xmm1
	subsd	%xmm1, %xmm0
	pxor	%xmm1, %xmm1
	comisd	%xmm1, %xmm0
	jbe	.L29
	movl	$1, %eax
	jmp	.L23
.L29:
	movl	$-1, %eax
.L23:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE14:
	.size	priceAcs, .-priceAcs
	.globl	priceDecs
	.type	priceDecs, @function
priceDecs:
.LFB15:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movsd	208(%rax), %xmm0
	movq	-16(%rbp), %rax
	movsd	208(%rax), %xmm1
	subsd	%xmm1, %xmm0
	movq	.LC1(%rip), %xmm1
	andpd	%xmm0, %xmm1
	movsd	.LC2(%rip), %xmm0
	comisd	%xmm1, %xmm0
	jbe	.L38
	movl	$0, %eax
	jmp	.L33
.L38:
	movq	-8(%rbp), %rax
	movsd	208(%rax), %xmm0
	movq	-16(%rbp), %rax
	movsd	208(%rax), %xmm1
	subsd	%xmm1, %xmm0
	pxor	%xmm1, %xmm1
	comisd	%xmm1, %xmm0
	jbe	.L39
	movl	$-1, %eax
	jmp	.L33
.L39:
	movl	$1, %eax
.L33:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE15:
	.size	priceDecs, .-priceDecs
	.globl	getComparator
	.type	getComparator, @function
getComparator:
.LFB16:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	cmpl	$6, -4(%rbp)
	ja	.L41
	movl	-4(%rbp), %eax
	leaq	0(,%rax,4), %rdx
	leaq	.L43(%rip), %rax
	movl	(%rdx,%rax), %eax
	cltq
	leaq	.L43(%rip), %rdx
	addq	%rdx, %rax
	notrack jmp	*%rax
	.section	.rodata
	.align 4
	.align 4
.L43:
	.long	.L41-.L43
	.long	.L48-.L43
	.long	.L47-.L43
	.long	.L46-.L43
	.long	.L45-.L43
	.long	.L44-.L43
	.long	.L42-.L43
	.text
.L48:
	leaq	titleAcs(%rip), %rax
	jmp	.L49
.L47:
	leaq	titleDecs(%rip), %rax
	jmp	.L49
.L46:
	leaq	pagesAcs(%rip), %rax
	jmp	.L49
.L45:
	leaq	pagesDecs(%rip), %rax
	jmp	.L49
.L44:
	leaq	priceAcs(%rip), %rax
	jmp	.L49
.L42:
	leaq	priceDecs(%rip), %rax
	jmp	.L49
.L41:
	movl	$0, %eax
.L49:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE16:
	.size	getComparator, .-getComparator
	.section	.rodata
	.align 8
.LC0:
	.long	-4194304
	.long	1105199103
	.align 16
.LC1:
	.long	-1
	.long	2147483647
	.long	0
	.long	0
	.align 8
.LC2:
	.long	-350469331
	.long	1058682594
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
