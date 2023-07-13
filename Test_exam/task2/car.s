	.file	"car.c"
	.text
	.globl	modelAcs
	.type	modelAcs, @function
modelAcs:
.LFB0:
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
.LFE0:
	.size	modelAcs, .-modelAcs
	.globl	modelDecs
	.type	modelDecs, @function
modelDecs:
.LFB1:
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
.LFE1:
	.size	modelDecs, .-modelDecs
	.globl	speedAcs
	.type	speedAcs, @function
speedAcs:
.LFB2:
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
	movzbl	20(%rax), %eax
	movzbl	%al, %edx
	movq	-16(%rbp), %rax
	movzbl	20(%rax), %eax
	movzbl	%al, %ecx
	movl	%edx, %eax
	subl	%ecx, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	speedAcs, .-speedAcs
	.globl	speedDecs
	.type	speedDecs, @function
speedDecs:
.LFB3:
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
	movzbl	20(%rax), %eax
	movzbl	%al, %edx
	movq	-8(%rbp), %rax
	movzbl	20(%rax), %eax
	movzbl	%al, %ecx
	movl	%edx, %eax
	subl	%ecx, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	speedDecs, .-speedDecs
	.globl	priceAcs
	.type	priceAcs, @function
priceAcs:
.LFB4:
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
	movsd	24(%rax), %xmm0
	movq	-16(%rbp), %rax
	movsd	24(%rax), %xmm1
	subsd	%xmm1, %xmm0
	movq	.LC0(%rip), %xmm1
	andpd	%xmm0, %xmm1
	movsd	.LC1(%rip), %xmm0
	comisd	%xmm1, %xmm0
	jbe	.L17
	movl	$0, %eax
	jmp	.L12
.L17:
	movq	-8(%rbp), %rax
	movsd	24(%rax), %xmm0
	movq	-16(%rbp), %rax
	movsd	24(%rax), %xmm1
	subsd	%xmm1, %xmm0
	pxor	%xmm1, %xmm1
	comisd	%xmm1, %xmm0
	jbe	.L18
	movl	$1, %eax
	jmp	.L12
.L18:
	movl	$-1, %eax
.L12:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	priceAcs, .-priceAcs
	.globl	priceDecs
	.type	priceDecs, @function
priceDecs:
.LFB5:
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
	movsd	24(%rax), %xmm0
	movq	-16(%rbp), %rax
	movsd	24(%rax), %xmm1
	subsd	%xmm1, %xmm0
	movq	.LC0(%rip), %xmm1
	andpd	%xmm0, %xmm1
	movsd	.LC1(%rip), %xmm0
	comisd	%xmm1, %xmm0
	jbe	.L27
	movl	$0, %eax
	jmp	.L22
.L27:
	movq	-8(%rbp), %rax
	movsd	24(%rax), %xmm0
	movq	-16(%rbp), %rax
	movsd	24(%rax), %xmm1
	subsd	%xmm1, %xmm0
	pxor	%xmm1, %xmm1
	comisd	%xmm1, %xmm0
	jbe	.L28
	movl	$-1, %eax
	jmp	.L22
.L28:
	movl	$1, %eax
.L22:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	priceDecs, .-priceDecs
	.globl	getComparator
	.type	getComparator, @function
getComparator:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	cmpl	$6, -4(%rbp)
	ja	.L30
	movl	-4(%rbp), %eax
	leaq	0(,%rax,4), %rdx
	leaq	.L32(%rip), %rax
	movl	(%rdx,%rax), %eax
	cltq
	leaq	.L32(%rip), %rdx
	addq	%rdx, %rax
	notrack jmp	*%rax
	.section	.rodata
	.align 4
	.align 4
.L32:
	.long	.L30-.L32
	.long	.L37-.L32
	.long	.L36-.L32
	.long	.L35-.L32
	.long	.L34-.L32
	.long	.L33-.L32
	.long	.L31-.L32
	.text
.L37:
	leaq	modelAcs(%rip), %rax
	jmp	.L38
.L36:
	leaq	modelDecs(%rip), %rax
	jmp	.L38
.L35:
	leaq	speedAcs(%rip), %rax
	jmp	.L38
.L34:
	leaq	speedDecs(%rip), %rax
	jmp	.L38
.L33:
	leaq	priceAcs(%rip), %rax
	jmp	.L38
.L31:
	leaq	priceDecs(%rip), %rax
	jmp	.L38
.L30:
	movl	$0, %eax
.L38:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	getComparator, .-getComparator
	.section	.rodata
	.align 16
.LC0:
	.long	-1
	.long	2147483647
	.long	0
	.long	0
	.align 8
.LC1:
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
