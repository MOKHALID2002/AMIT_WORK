	.file	"main.c"
	.text
	.comm	arr, 320, 5
	.comm	checkfull, 4, 2
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "\12------->(Data Base)<-------\0"
	.align 8
.LC1:
	.ascii "\12 (1)-Add new entry to the database\0"
	.align 8
.LC2:
	.ascii "\12 (2)-Display data of an entry using ID\0"
.LC3:
	.ascii "\12 (3)-Check if ID exists full\0"
	.align 8
.LC4:
	.ascii "\12 (4)-Check if the database is full\0"
	.align 8
.LC5:
	.ascii "\12 (5)-Delete entry using the ID\0"
.LC6:
	.ascii "\12 (6)-the number of entries\0"
	.align 8
.LC7:
	.ascii "\12 (7)-Get the list of IDs of the students\0"
.LC8:
	.ascii "\12 (0)-Close the program\0"
.LC9:
	.ascii "\12 Please pick the Operation: \0"
.LC10:
	.ascii "%d\0"
	.align 8
.LC11:
	.ascii "\12Please enter the Student ID: \0"
	.align 8
.LC12:
	.ascii "\12The ID can't be Zero Please enter the ID again\0"
	.align 8
.LC13:
	.ascii "\12 The ID you entered already exists please enter again\0"
	.align 8
.LC14:
	.ascii "Please enter the Student year: \0"
.LC15:
	.ascii "Please enter Course %d ID: \0"
	.align 8
.LC16:
	.ascii "Please enter Course %d Grade: \0"
.LC17:
	.ascii "\12Data is added successfully\12 \0"
	.align 8
.LC18:
	.ascii "\12\12Enter (1) to go for the Data base List \0"
	.align 8
.LC19:
	.ascii "\12or Enter any value to close the Program : \0"
	.align 8
.LC20:
	.ascii "\12Sorry data not added please enter it again \0"
	.align 8
.LC21:
	.ascii "\12Be sure the (Grade from 0 to 100) also (Year less than 2023)\0"
.LC22:
	.ascii "\12Sorry Data Base is fully \0"
.LC23:
	.ascii "\12Enter the ID to Display : \0"
	.align 8
.LC24:
	.ascii "\12or Enter(0) to close the Program : \0"
	.align 8
.LC25:
	.ascii "\12 The ID you entered is not exists\0"
	.align 8
.LC26:
	.ascii "\12if you want to go for list enter (1) \0"
	.align 8
.LC27:
	.ascii "\12if you need to Display another ID enter any value : \0"
	.align 8
.LC28:
	.ascii "\12Please enter the ID to check : \0"
	.align 8
.LC29:
	.ascii "\12 The ID you entered is exists\0"
	.align 8
.LC30:
	.ascii "\12 The ID you entered not exists\0"
.LC31:
	.ascii "\12 \11Have a nice day\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$96, %rsp
	.seh_stackalloc	96
	.seh_endprologue
	call	__main
	movl	$0, -12(%rbp)
.L2:
	leaq	.LC0(%rip), %rcx
	call	puts
	leaq	.LC1(%rip), %rcx
	call	printf
	leaq	.LC2(%rip), %rcx
	call	printf
	leaq	.LC3(%rip), %rcx
	call	printf
	leaq	.LC4(%rip), %rcx
	call	printf
	leaq	.LC5(%rip), %rcx
	call	printf
	leaq	.LC6(%rip), %rcx
	call	printf
	leaq	.LC7(%rip), %rcx
	call	printf
	leaq	.LC8(%rip), %rcx
	call	puts
	leaq	.LC9(%rip), %rcx
	call	printf
	leaq	-20(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC10(%rip), %rcx
	call	scanf
	movl	-20(%rbp), %eax
	cmpl	$2, %eax
	je	.L3
	cmpl	$3, %eax
	je	.L4
	cmpl	$1, %eax
	jne	.L5
.L6:
	movl	$0, -16(%rbp)
	cmpl	$1, -16(%rbp)
	ja	.L7
	leaq	arr(%rip), %rax
	movl	-16(%rbp), %edx
	salq	$5, %rdx
	addq	%rdx, %rax
	movl	(%rax), %eax
	testl	%eax, %eax
	jne	.L8
	leaq	.LC11(%rip), %rcx
	call	printf
	leaq	-48(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC10(%rip), %rcx
	call	scanf
	movl	-48(%rbp), %eax
	movl	%eax, %ecx
	call	SDB_IsIdExist
	movzbl	%al, %eax
	movl	%eax, -12(%rbp)
	movl	-48(%rbp), %eax
	testl	%eax, %eax
	jne	.L9
	leaq	.LC12(%rip), %rcx
	call	puts
	jmp	.L6
.L9:
	cmpl	$1, -12(%rbp)
	jne	.L10
	leaq	.LC13(%rip), %rcx
	call	printf
	jmp	.L6
.L10:
	leaq	.LC14(%rip), %rcx
	call	printf
	leaq	-52(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC10(%rip), %rcx
	call	scanf
	movl	$0, -8(%rbp)
	jmp	.L11
.L12:
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %edx
	leaq	.LC15(%rip), %rcx
	call	printf
	leaq	-44(%rbp), %rax
	movl	-8(%rbp), %edx
	salq	$2, %rdx
	addq	%rdx, %rax
	movq	%rax, %rdx
	leaq	.LC10(%rip), %rcx
	call	scanf
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %edx
	leaq	.LC16(%rip), %rcx
	call	printf
	leaq	-32(%rbp), %rax
	movl	-8(%rbp), %edx
	salq	$2, %rdx
	addq	%rdx, %rax
	movq	%rax, %rdx
	leaq	.LC10(%rip), %rcx
	call	scanf
	addl	$1, -8(%rbp)
.L11:
	cmpl	$2, -8(%rbp)
	jbe	.L12
	movl	-52(%rbp), %edx
	movl	-48(%rbp), %eax
	leaq	-44(%rbp), %r8
	leaq	-32(%rbp), %rcx
	movq	%r8, %r9
	movq	%rcx, %r8
	movl	%eax, %ecx
	call	SDB_AddEntry
	movzbl	%al, %eax
	movl	%eax, -4(%rbp)
.L8:
	cmpl	$1, -4(%rbp)
	jne	.L13
	leaq	checkfull(%rip), %rax
	movl	(%rax), %eax
	leal	1(%rax), %edx
	leaq	checkfull(%rip), %rax
	movl	%edx, (%rax)
	leaq	.LC17(%rip), %rcx
	call	printf
	leaq	.LC18(%rip), %rcx
	call	printf
	leaq	.LC19(%rip), %rcx
	call	printf
	leaq	-56(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC10(%rip), %rcx
	call	scanf
	movl	-56(%rbp), %eax
	cmpl	$1, %eax
	jne	.L23
	jmp	.L2
.L13:
	leaq	arr(%rip), %rax
	movl	-16(%rbp), %edx
	salq	$5, %rdx
	addq	%rdx, %rax
	movl	$0, (%rax)
	leaq	.LC20(%rip), %rcx
	call	printf
	leaq	.LC21(%rip), %rcx
	call	puts
	jmp	.L6
.L7:
	leaq	.LC22(%rip), %rcx
	call	printf
	leaq	.LC18(%rip), %rcx
	call	printf
	leaq	.LC19(%rip), %rcx
	call	printf
	leaq	-56(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC10(%rip), %rcx
	call	scanf
	movl	-56(%rbp), %eax
	cmpl	$1, %eax
	jne	.L24
	jmp	.L2
.L3:
	leaq	.LC23(%rip), %rcx
	call	printf
	leaq	-48(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC10(%rip), %rcx
	call	scanf
	movl	-48(%rbp), %eax
	testl	%eax, %eax
	jne	.L16
	leaq	.LC12(%rip), %rcx
	call	printf
	jmp	.L3
.L16:
	movl	-48(%rbp), %eax
	movl	%eax, %ecx
	call	SDB_IsIdExist
	testb	%al, %al
	je	.L17
	movl	-48(%rbp), %eax
	movl	%eax, %ecx
	call	SDB_ReadEntry
	leaq	.LC18(%rip), %rcx
	call	printf
	leaq	.LC24(%rip), %rcx
	call	printf
	leaq	-56(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC10(%rip), %rcx
	call	scanf
	movl	-56(%rbp), %eax
	cmpl	$1, %eax
	jne	.L25
	jmp	.L2
.L17:
	leaq	.LC25(%rip), %rcx
	call	printf
	leaq	.LC26(%rip), %rcx
	call	printf
	leaq	.LC27(%rip), %rcx
	call	printf
	leaq	-56(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC10(%rip), %rcx
	call	scanf
	movl	-56(%rbp), %eax
	cmpl	$1, %eax
	jne	.L3
	jmp	.L2
.L4:
	leaq	.LC28(%rip), %rcx
	call	printf
	leaq	-48(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC10(%rip), %rcx
	call	scanf
	movl	-48(%rbp), %eax
	movl	%eax, %ecx
	call	SDB_IsIdExist
	movzbl	%al, %eax
	movl	%eax, -12(%rbp)
	movl	-48(%rbp), %eax
	testl	%eax, %eax
	jne	.L20
	leaq	.LC12(%rip), %rcx
	call	printf
	jmp	.L4
.L20:
	cmpl	$1, -12(%rbp)
	jne	.L21
	leaq	.LC29(%rip), %rcx
	call	printf
	jmp	.L2
.L21:
	leaq	.LC30(%rip), %rcx
	call	printf
	jmp	.L2
.L23:
	nop
	jmp	.L5
.L24:
	nop
	jmp	.L5
.L25:
	nop
.L5:
	leaq	.LC31(%rip), %rcx
	call	puts
	movl	$0, %eax
	addq	$96, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	SDB_AddEntry
	.def	SDB_AddEntry;	.scl	2;	.type	32;	.endef
	.seh_proc	SDB_AddEntry
SDB_AddEntry:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movq	%r8, 32(%rbp)
	movq	%r9, 40(%rbp)
	movq	32(%rbp), %rax
	movl	(%rax), %eax
	cmpl	$100, %eax
	ja	.L27
	movq	32(%rbp), %rax
	addq	$4, %rax
	movl	(%rax), %eax
	cmpl	$100, %eax
	ja	.L27
	movq	32(%rbp), %rax
	addq	$8, %rax
	movl	(%rax), %eax
	cmpl	$100, %eax
	ja	.L27
	cmpl	$2022, 24(%rbp)
	ja	.L27
	leaq	checkfull(%rip), %rax
	movl	(%rax), %edx
	leaq	arr(%rip), %rax
	movslq	%edx, %rdx
	salq	$5, %rdx
	addq	%rdx, %rax
	movl	16(%rbp), %edx
	movl	%edx, (%rax)
	leaq	checkfull(%rip), %rax
	movl	(%rax), %edx
	leaq	arr(%rip), %rax
	movslq	%edx, %rdx
	salq	$5, %rdx
	addq	%rdx, %rax
	addq	$4, %rax
	movl	24(%rbp), %edx
	movl	%edx, (%rax)
	leaq	checkfull(%rip), %rax
	movl	(%rax), %ecx
	movq	40(%rbp), %rax
	movl	(%rax), %edx
	leaq	arr(%rip), %rax
	movslq	%ecx, %rcx
	salq	$5, %rcx
	addq	%rcx, %rax
	addq	$8, %rax
	movl	%edx, (%rax)
	leaq	checkfull(%rip), %rax
	movl	(%rax), %ecx
	movq	40(%rbp), %rax
	movl	4(%rax), %edx
	leaq	arr(%rip), %rax
	movslq	%ecx, %rcx
	salq	$5, %rcx
	addq	%rcx, %rax
	addq	$16, %rax
	movl	%edx, (%rax)
	leaq	checkfull(%rip), %rax
	movl	(%rax), %ecx
	movq	40(%rbp), %rax
	movl	8(%rax), %edx
	leaq	arr(%rip), %rax
	movslq	%ecx, %rcx
	salq	$5, %rcx
	addq	%rcx, %rax
	addq	$24, %rax
	movl	%edx, (%rax)
	leaq	checkfull(%rip), %rax
	movl	(%rax), %ecx
	movq	32(%rbp), %rax
	movl	(%rax), %edx
	leaq	arr(%rip), %rax
	movslq	%ecx, %rcx
	salq	$5, %rcx
	addq	%rcx, %rax
	addq	$12, %rax
	movl	%edx, (%rax)
	leaq	checkfull(%rip), %rax
	movl	(%rax), %ecx
	movq	32(%rbp), %rax
	movl	4(%rax), %edx
	leaq	arr(%rip), %rax
	movslq	%ecx, %rcx
	salq	$5, %rcx
	addq	%rcx, %rax
	addq	$20, %rax
	movl	%edx, (%rax)
	leaq	checkfull(%rip), %rax
	movl	(%rax), %ecx
	movq	32(%rbp), %rax
	movl	8(%rax), %edx
	leaq	arr(%rip), %rax
	movslq	%ecx, %rcx
	salq	$5, %rcx
	addq	%rcx, %rax
	addq	$28, %rax
	movl	%edx, (%rax)
	movl	$1, %eax
	jmp	.L28
.L27:
	movl	$0, %eax
.L28:
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC32:
	.ascii "\12Student ID   : %d\0"
.LC33:
	.ascii "\12Student Year : %d\0"
.LC34:
	.ascii "\12Course 1 ID  : %d\0"
.LC35:
	.ascii "\12Course 1 Grade : %d\0"
.LC36:
	.ascii "\12Course 2 ID  : %d\0"
.LC37:
	.ascii "\12Course 3 ID  : %d\0"
	.text
	.globl	SDB_ReadEntry
	.def	SDB_ReadEntry;	.scl	2;	.type	32;	.endef
	.seh_proc	SDB_ReadEntry
SDB_ReadEntry:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L30
.L32:
	leaq	arr(%rip), %rax
	movl	-4(%rbp), %edx
	salq	$5, %rdx
	addq	%rdx, %rax
	movl	(%rax), %eax
	cmpl	%eax, 16(%rbp)
	jne	.L31
	leaq	arr(%rip), %rax
	movl	-4(%rbp), %edx
	salq	$5, %rdx
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, %edx
	leaq	.LC32(%rip), %rcx
	call	printf
	leaq	arr(%rip), %rax
	movl	-4(%rbp), %edx
	salq	$5, %rdx
	addq	%rdx, %rax
	addq	$4, %rax
	movl	(%rax), %eax
	movl	%eax, %edx
	leaq	.LC33(%rip), %rcx
	call	printf
	leaq	arr(%rip), %rax
	movl	-4(%rbp), %edx
	salq	$5, %rdx
	addq	%rdx, %rax
	addq	$8, %rax
	movl	(%rax), %eax
	movl	%eax, %edx
	leaq	.LC34(%rip), %rcx
	call	printf
	leaq	arr(%rip), %rax
	movl	-4(%rbp), %edx
	salq	$5, %rdx
	addq	%rdx, %rax
	addq	$12, %rax
	movl	(%rax), %eax
	movl	%eax, %edx
	leaq	.LC35(%rip), %rcx
	call	printf
	leaq	arr(%rip), %rax
	movl	-4(%rbp), %edx
	salq	$5, %rdx
	addq	%rdx, %rax
	addq	$16, %rax
	movl	(%rax), %eax
	movl	%eax, %edx
	leaq	.LC36(%rip), %rcx
	call	printf
	leaq	arr(%rip), %rax
	movl	-4(%rbp), %edx
	salq	$5, %rdx
	addq	%rdx, %rax
	addq	$20, %rax
	movl	(%rax), %eax
	movl	%eax, %edx
	leaq	.LC35(%rip), %rcx
	call	printf
	leaq	arr(%rip), %rax
	movl	-4(%rbp), %edx
	salq	$5, %rdx
	addq	%rdx, %rax
	addq	$24, %rax
	movl	(%rax), %eax
	movl	%eax, %edx
	leaq	.LC37(%rip), %rcx
	call	printf
	leaq	arr(%rip), %rax
	movl	-4(%rbp), %edx
	salq	$5, %rdx
	addq	%rdx, %rax
	addq	$28, %rax
	movl	(%rax), %eax
	movl	%eax, %edx
	leaq	.LC35(%rip), %rcx
	call	printf
.L31:
	addl	$1, -4(%rbp)
.L30:
	cmpl	$1, -4(%rbp)
	jbe	.L32
	nop
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	SDB_IsIdExist
	.def	SDB_IsIdExist;	.scl	2;	.type	32;	.endef
	.seh_proc	SDB_IsIdExist
SDB_IsIdExist:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L34
.L37:
	leaq	arr(%rip), %rax
	movl	-4(%rbp), %edx
	salq	$5, %rdx
	addq	%rdx, %rax
	movl	(%rax), %eax
	cmpl	%eax, 16(%rbp)
	jne	.L35
	movl	$1, %eax
	jmp	.L36
.L35:
	addl	$1, -4(%rbp)
.L34:
	cmpl	$1, -4(%rbp)
	jbe	.L37
	movl	$0, %eax
.L36:
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	puts;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	scanf;	.scl	2;	.type	32;	.endef
