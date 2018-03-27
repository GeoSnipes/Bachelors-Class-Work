void main()
{
	char num1 = 2; // 00000010 => 11111101 => 11111110
	char num2=3;
	char res;
	__asm
	{
		movzx eax, num1
		sub eax, '0'

			movzx ebx, num2
			sub ebx, '0'

			add eax, ebx
			add eax, '0'
			mov [res], al

			mov eax, 4
			mov ebx, 1
			movzx ecx, res
			mov edx, 2
			int 0x80

			mov eax, 1
			int 0x80

	}
}
