	.file	"single_list.c"
	.text
	.globl	create_new
	.type	create_new, @function
create_new:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	$0, -8(%rbp)
	movl	$16, %edi
	call	malloc
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	je	.L2
	movq	-8(%rbp), %rax
	movl	-20(%rbp), %edx
	movl	%edx, (%rax)
	movq	-8(%rbp), %rax
	movq	$0, 8(%rax)
.L2:
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	create_new, .-create_new
	.globl	insertAtFront
	.type	insertAtFront, @function
insertAtFront:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	$0, -12(%rbp)
	movq	$0, -8(%rbp)
	movl	-28(%rbp), %eax
	movl	%eax, %edi
	call	create_new
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	jne	.L5
	movl	$-1, -12(%rbp)
.L5:
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	testq	%rax, %rax
	jne	.L6
	movq	-24(%rbp), %rax
	movq	-8(%rbp), %rdx
	movq	%rdx, (%rax)
	jmp	.L7
.L6:
	movq	-24(%rbp), %rax
	movq	(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, 8(%rax)
	movq	-24(%rbp), %rax
	movq	-8(%rbp), %rdx
	movq	%rdx, (%rax)
.L7:
	movl	-12(%rbp), %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	insertAtFront, .-insertAtFront
	.section	.rodata
.LC0:
	.string	"Why am I breaking now?\n"
.LC1:
	.string	"Data to search is %d\n"
.LC2:
	.string	"Hurray you found me!\n"
	.text
	.globl	searchMylist
	.type	searchMylist, @function
searchMylist:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	$0, -12(%rbp)
	cmpq	$0, -24(%rbp)
	jne	.L10
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$23, %edx
	movl	$1, %esi
	movl	$.LC0, %edi
	call	fwrite
	movl	$-1, -12(%rbp)
	jmp	.L11
.L10:
	movq	stderr(%rip), %rax
	movl	-28(%rbp), %edx
	movl	$.LC1, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	movq	-24(%rbp), %rax
	movq	%rax, -8(%rbp)
	jmp	.L12
.L14:
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	cmpl	-28(%rbp), %eax
	jne	.L13
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$21, %edx
	movl	$1, %esi
	movl	$.LC2, %edi
	call	fwrite
.L13:
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -8(%rbp)
.L12:
	cmpq	$0, -8(%rbp)
	jne	.L14
.L11:
	movl	-12(%rbp), %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	searchMylist, .-searchMylist
	.globl	insertAtBack
	.type	insertAtBack, @function
insertAtBack:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movq	$0, -8(%rbp)
	movl	-28(%rbp), %eax
	movl	%eax, %edi
	call	create_new
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	jne	.L17
	movl	$-1, %eax
	jmp	.L18
.L17:
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	testq	%rax, %rax
	jne	.L19
	movq	-24(%rbp), %rax
	movq	-8(%rbp), %rdx
	movq	%rdx, (%rax)
	movl	$0, %eax
	jmp	.L18
.L19:
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -16(%rbp)
	jmp	.L20
.L21:
	movq	-16(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -16(%rbp)
.L20:
	movq	-16(%rbp), %rax
	movq	8(%rax), %rax
	testq	%rax, %rax
	jne	.L21
	movq	-16(%rbp), %rax
	movq	-8(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movl	$0, %eax
.L18:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	insertAtBack, .-insertAtBack
	.globl	return_list
	.type	return_list, @function
return_list:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movl	%edi, -36(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, -20(%rbp)
	movq	$0, -16(%rbp)
	jmp	.L23
.L24:
	movl	-36(%rbp), %ecx
	movl	$1717986919, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	$2, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, -20(%rbp)
	movl	-36(%rbp), %ecx
	movl	$1717986919, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	$2, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	movl	%eax, -36(%rbp)
	movl	-20(%rbp), %edx
	leaq	-16(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	insertAtBack
.L23:
	cmpl	$0, -36(%rbp)
	jne	.L24
	movq	-16(%rbp), %rax
	movq	-8(%rbp), %rsi
	xorq	%fs:40, %rsi
	je	.L26
	call	__stack_chk_fail
.L26:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	return_list, .-return_list
	.section	.rodata
.LC3:
	.string	"list contains %d\n"
	.text
	.globl	print_list
	.type	print_list, @function
print_list:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -8(%rbp)
	jmp	.L28
.L29:
	movq	-8(%rbp), %rax
	movl	(%rax), %edx
	movq	stderr(%rip), %rax
	movl	$.LC3, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	movq	-8(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -8(%rbp)
.L28:
	cmpq	$0, -8(%rbp)
	jne	.L29
	movq	stderr(%rip), %rax
	movq	%rax, %rsi
	movl	$10, %edi
	call	fputc
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	print_list, .-print_list
	.globl	reverse_list
	.type	reverse_list, @function
reverse_list:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -40(%rbp)
	movq	$0, -24(%rbp)
	movq	$0, -16(%rbp)
	movq	$0, -8(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, -24(%rbp)
	jmp	.L31
.L32:
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -8(%rbp)
	movq	-24(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	-24(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, -24(%rbp)
.L31:
	cmpq	$0, -24(%rbp)
	jne	.L32
	movq	-16(%rbp), %rax
	movq	%rax, -40(%rbp)
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	reverse_list, .-reverse_list
	.globl	convert_numbers_to_list
	.type	convert_numbers_to_list, @function
convert_numbers_to_list:
.LFB9:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	$0, -8(%rbp)
	movl	-20(%rbp), %eax
	movl	%eax, %edi
	call	return_list
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	convert_numbers_to_list, .-convert_numbers_to_list
	.globl	list_len
	.type	list_len, @function
list_len:
.LFB10:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L37
.L38:
	addl	$1, -4(%rbp)
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -24(%rbp)
.L37:
	movq	-24(%rbp), %rax
	movq	8(%rax), %rax
	testq	%rax, %rax
	jne	.L38
	movl	-4(%rbp), %eax
	addl	$1, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	list_len, .-list_len
	.section	.rodata
.LC4:
	.string	"Len_a %d, Len_b %d\n"
.LC5:
	.string	"case 1\n"
.LC6:
	.string	"l1_>data is %d\n"
.LC7:
	.string	"l2_>data is %d\n"
.LC8:
	.string	"carry is >10\n"
.LC9:
	.string	"lets go next\n"
.LC10:
	.string	"made it to case 3\n"
.LC11:
	.string	"res %d\n"
	.text
	.globl	add_two_lists
	.type	add_two_lists, @function
add_two_lists:
.LFB11:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$112, %rsp
	movq	%rdi, -104(%rbp)
	movq	%rsi, -112(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, -68(%rbp)
	movl	$0, -64(%rbp)
	movl	$0, -60(%rbp)
	movl	$0, -84(%rbp)
	movl	$0, -80(%rbp)
	movl	$0, -76(%rbp)
	movl	$0, -72(%rbp)
	movq	-104(%rbp), %rax
	movq	%rax, -24(%rbp)
	movq	-112(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	list_len
	movl	%eax, -84(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	list_len
	movl	%eax, -80(%rbp)
	movq	stderr(%rip), %rax
	movl	-80(%rbp), %ecx
	movl	-84(%rbp), %edx
	movl	$.LC4, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	movq	$0, -48(%rbp)
	movl	-84(%rbp), %eax
	cmpl	-80(%rbp), %eax
	jle	.L41
	movl	$1, -76(%rbp)
	jmp	.L42
.L41:
	movl	-80(%rbp), %eax
	cmpl	-84(%rbp), %eax
	jle	.L43
	movl	$2, -76(%rbp)
	jmp	.L42
.L43:
	movl	$3, -76(%rbp)
.L42:
	movl	-76(%rbp), %eax
	cmpl	$2, %eax
	je	.L56
	cmpl	$3, %eax
	je	.L46
	cmpl	$1, %eax
	je	.L47
	jmp	.L55
.L47:
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$7, %edx
	movl	$1, %esi
	movl	$.LC5, %edi
	call	fwrite
	jmp	.L48
.L51:
	movq	-104(%rbp), %rax
	movl	(%rax), %edx
	movq	stderr(%rip), %rax
	movl	$.LC6, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	movq	-112(%rbp), %rax
	movl	(%rax), %edx
	movq	stderr(%rip), %rax
	movl	$.LC7, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	movq	-104(%rbp), %rax
	movl	(%rax), %edx
	movq	-112(%rbp), %rax
	movl	(%rax), %eax
	addl	%eax, %edx
	movl	-72(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, -68(%rbp)
	cmpl	$9, -68(%rbp)
	jle	.L49
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$13, %edx
	movl	$1, %esi
	movl	$.LC8, %edi
	call	fwrite
	movl	-68(%rbp), %eax
	subl	$10, %eax
	movl	%eax, -64(%rbp)
	movl	$1, -72(%rbp)
	movl	-64(%rbp), %edx
	leaq	-48(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	insertAtBack
	jmp	.L50
.L49:
	movl	$0, -72(%rbp)
	movl	-68(%rbp), %edx
	leaq	-48(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	insertAtBack
.L50:
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$13, %edx
	movl	$1, %esi
	movl	$.LC9, %edi
	call	fwrite
	movq	-104(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -104(%rbp)
	movq	-112(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -112(%rbp)
	subl	$1, -80(%rbp)
.L48:
	cmpl	$0, -80(%rbp)
	jne	.L51
	cmpl	$0, -72(%rbp)
	je	.L52
	movl	$0, -56(%rbp)
	movq	-104(%rbp), %rax
	movl	(%rax), %edx
	movl	-72(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, -56(%rbp)
	movl	-56(%rbp), %edx
	leaq	-48(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	insertAtBack
	movq	-104(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -104(%rbp)
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	print_list
.L52:
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	print_list
	movq	-48(%rbp), %rax
	movq	%rax, -40(%rbp)
	jmp	.L53
.L54:
	movq	-40(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -40(%rbp)
.L53:
	movq	-40(%rbp), %rax
	movq	8(%rax), %rax
	testq	%rax, %rax
	jne	.L54
	movq	-40(%rbp), %rax
	movq	-104(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	-48(%rbp), %rax
	movq	-40(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	print_list
	jmp	.L55
.L59:
	movq	-104(%rbp), %rax
	movl	(%rax), %edx
	movq	stderr(%rip), %rax
	movl	$.LC6, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	movq	-112(%rbp), %rax
	movl	(%rax), %edx
	movq	stderr(%rip), %rax
	movl	$.LC7, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	movq	-104(%rbp), %rax
	movl	(%rax), %edx
	movq	-112(%rbp), %rax
	movl	(%rax), %eax
	addl	%eax, %edx
	movl	-72(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, -68(%rbp)
	cmpl	$9, -68(%rbp)
	jle	.L57
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$13, %edx
	movl	$1, %esi
	movl	$.LC8, %edi
	call	fwrite
	movl	-68(%rbp), %eax
	subl	$10, %eax
	movl	%eax, -64(%rbp)
	movl	$1, -72(%rbp)
	movl	-64(%rbp), %edx
	leaq	-48(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	insertAtBack
	jmp	.L58
.L57:
	movl	$0, -72(%rbp)
	movl	-68(%rbp), %edx
	leaq	-48(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	insertAtBack
.L58:
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$13, %edx
	movl	$1, %esi
	movl	$.LC9, %edi
	call	fwrite
	movq	-104(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -104(%rbp)
	movq	-112(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -112(%rbp)
	subl	$1, -84(%rbp)
.L56:
	cmpl	$0, -84(%rbp)
	jne	.L59
	cmpl	$0, -72(%rbp)
	je	.L60
	movl	$0, -52(%rbp)
	movq	-112(%rbp), %rax
	movl	(%rax), %edx
	movl	-72(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, -52(%rbp)
	movl	-52(%rbp), %edx
	leaq	-48(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	insertAtBack
	movq	-112(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -112(%rbp)
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	print_list
.L60:
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	print_list
	movq	-48(%rbp), %rax
	movq	%rax, -32(%rbp)
	jmp	.L61
.L62:
	movq	-32(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -32(%rbp)
.L61:
	movq	-32(%rbp), %rax
	movq	8(%rax), %rax
	testq	%rax, %rax
	jne	.L62
	movq	-32(%rbp), %rax
	movq	-112(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	-48(%rbp), %rax
	movq	-32(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	print_list
	jmp	.L55
.L46:
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$18, %edx
	movl	$1, %esi
	movl	$.LC10, %edi
	call	fwrite
	jmp	.L63
.L66:
	subl	$1, -84(%rbp)
	movq	-104(%rbp), %rax
	movl	(%rax), %edx
	movq	-112(%rbp), %rax
	movl	(%rax), %eax
	addl	%eax, %edx
	movl	-72(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, -64(%rbp)
	movq	stderr(%rip), %rax
	movl	-64(%rbp), %edx
	movl	$.LC11, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	cmpl	$9, -64(%rbp)
	jle	.L64
	movl	-64(%rbp), %eax
	subl	$10, %eax
	movl	%eax, -68(%rbp)
	movl	$1, -72(%rbp)
	movl	-68(%rbp), %edx
	leaq	-48(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	insertAtBack
	jmp	.L65
.L64:
	movl	$0, -72(%rbp)
	movl	-64(%rbp), %edx
	leaq	-48(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	insertAtBack
.L65:
	movq	-104(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -104(%rbp)
	movq	-112(%rbp), %rax
	movq	8(%rax), %rax
	movq	%rax, -112(%rbp)
.L63:
	cmpl	$0, -84(%rbp)
	jne	.L66
	cmpl	$0, -72(%rbp)
	je	.L67
	movl	-72(%rbp), %edx
	leaq	-48(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	insertAtBack
.L67:
	movq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	print_list
	nop
.L55:
	nop
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L68
	call	__stack_chk_fail
.L68:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	add_two_lists, .-add_two_lists
	.section	.rodata
.LC12:
	.string	"Enter your choice\n"
	.align 8
.LC13:
	.string	"1: Insert at front\n2:Insert at end\n3:Search\n4:Delete\n5:Add two numbers\n"
.LC14:
	.string	"%d"
	.align 8
.LC15:
	.string	"Please insert some data! You don't want your data to be zero :D\n"
.LC16:
	.string	"Let us search for the data!!\n"
.LC17:
	.string	"Am I Null %d\n"
	.align 8
.LC18:
	.string	"lets add two numbers, please type two numbers\n"
.LC19:
	.string	"%d %d"
	.text
	.globl	main
	.type	main, @function
main:
.LFB12:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$80, %rsp
	movl	%edi, -68(%rbp)
	movq	%rsi, -80(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, -52(%rbp)
	movl	$0, -48(%rbp)
	movl	$0, -44(%rbp)
	movl	$0, -40(%rbp)
	movl	$0, -36(%rbp)
	movq	$0, -32(%rbp)
	movq	$0, -24(%rbp)
	movq	$0, -16(%rbp)
.L79:
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$18, %edx
	movl	$1, %esi
	movl	$.LC12, %edi
	call	fwrite
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$71, %edx
	movl	$1, %esi
	movl	$.LC13, %edi
	call	fwrite
	leaq	-52(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC14, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	-52(%rbp), %eax
	cmpl	$6, %eax
	ja	.L81
	movl	%eax, %eax
	movq	.L72(,%rax,8), %rax
	jmp	*%rax
	.section	.rodata
	.align 8
	.align 4
.L72:
	.quad	.L81
	.quad	.L71
	.quad	.L81
	.quad	.L74
	.quad	.L81
	.quad	.L76
	.quad	.L77
	.text
.L71:
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$64, %edx
	movl	$1, %esi
	movl	$.LC15, %edi
	call	fwrite
	leaq	-48(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC14, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	-48(%rbp), %edx
	leaq	-32(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	insertAtFront
	jmp	.L78
.L74:
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$29, %edx
	movl	$1, %esi
	movl	$.LC16, %edi
	call	fwrite
	leaq	-44(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC14, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movq	-32(%rbp), %rax
	movl	(%rax), %edx
	movq	stderr(%rip), %rax
	movl	$.LC17, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf
	movl	-44(%rbp), %edx
	movq	-32(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	searchMylist
	jmp	.L78
.L76:
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$46, %edx
	movl	$1, %esi
	movl	$.LC18, %edi
	call	fwrite
	leaq	-36(%rbp), %rdx
	leaq	-40(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC19, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	-40(%rbp), %eax
	movl	%eax, %edi
	call	convert_numbers_to_list
	movq	%rax, -24(%rbp)
	movl	-36(%rbp), %eax
	movl	%eax, %edi
	call	convert_numbers_to_list
	movq	%rax, -16(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	print_list
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	print_list
	movq	-16(%rbp), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	add_two_lists
	jmp	.L78
.L77:
	movl	$0, %edi
	call	exit
.L81:
	nop
.L78:
	jmp	.L79
	.cfi_endproc
.LFE12:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.9) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
