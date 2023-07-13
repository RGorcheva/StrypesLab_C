	.file	"main.c"
	.text
	.globl	carArr
	.data
	.align 32
	.type	carArr, @object
	.size	carArr, 320
carArr:
	.string	"Mazda2"
	.zero	13
	.byte	-106
	.zero	3
	.long	0
	.long	1088493312
	.string	"Mazda6"
	.zero	13
	.byte	-56
	.zero	3
	.long	0
	.long	1089453312
	.string	"Opel corsa"
	.zero	9
	.byte	-111
	.zero	3
	.long	0
	.long	1087196160
	.string	"Toyota Yaris"
	.zero	7
	.byte	-76
	.zero	3
	.long	0
	.long	1086812160
	.string	"Renault Laguna"
	.zero	5
	.byte	-71
	.zero	3
	.long	0
	.long	1089621888
	.string	"Mercedes Benz"
	.zero	6
	.byte	-41
	.zero	3
	.long	0
	.long	1090021888
	.string	"BMW 3"
	.zero	14
	.byte	-56
	.zero	3
	.long	0
	.long	1087412736
	.string	"Ferrari"
	.zero	12
	.byte	-36
	.zero	3
	.long	0
	.long	1090005888
	.string	"Citroen C3"
	.zero	9
	.byte	-111
	.zero	3
	.long	0
	.long	1088493312
	.string	"Hunday"
	.zero	13
	.byte	-106
	.zero	3
	.long	0
	.long	1089293312
	.section	.rodata
.LC0:
	.string	"%d"
	.align 8
.LC1:
	.string	"You can choose between 1 and 6!\nYour choice: "
.LC2:
	.string	"Automobile %d:\n"
.LC3:
	.string	"Model: %s,\n"
.LC4:
	.string	"Max speed: %d,\n"
.LC5:
	.string	"price: %.2lf.\n\n"
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
	subq	$32, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, -20(%rbp)
	movl	$0, -16(%rbp)
	leaq	-20(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	%eax, -16(%rbp)
	nop
.L2:
	call	getchar@PLT
	cmpl	$10, %eax
	jne	.L2
	jmp	.L3
.L5:
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-20(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	%eax, -16(%rbp)
	nop
.L4:
	call	getchar@PLT
	cmpl	$10, %eax
	jne	.L4
.L3:
	cmpl	$0, -16(%rbp)
	je	.L5
	movl	-20(%rbp), %eax
	movl	%eax, %edi
	call	getComparator@PLT
	movq	%rax, %rcx
	movl	$32, %edx
	movl	$10, %esi
	leaq	carArr(%rip), %rax
	movq	%rax, %rdi
	call	qsort@PLT
	movl	$0, -12(%rbp)
	jmp	.L6
.L7:
	movl	-12(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %esi
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-12(%rbp), %eax
	cltq
	salq	$5, %rax
	movq	%rax, %rdx
	leaq	carArr(%rip), %rax
	addq	%rdx, %rax
	movq	%rax, %rsi
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-12(%rbp), %eax
	cltq
	salq	$5, %rax
	movq	%rax, %rdx
	leaq	20+carArr(%rip), %rax
	movzbl	(%rdx,%rax), %eax
	movzbl	%al, %eax
	movl	%eax, %esi
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-12(%rbp), %eax
	cltq
	salq	$5, %rax
	movq	%rax, %rdx
	leaq	24+carArr(%rip), %rax
	movq	(%rdx,%rax), %rax
	movq	%rax, %xmm0
	leaq	.LC5(%rip), %rax
	movq	%rax, %rdi
	movl	$1, %eax
	call	printf@PLT
	addl	$1, -12(%rbp)
.L6:
	cmpl	$9, -12(%rbp)
	jle	.L7
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L9
	call	__stack_chk_fail@PLT
.L9:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main
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
