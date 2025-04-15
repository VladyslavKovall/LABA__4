int Make_Sum(int one_value, int two_value) {
	__asm {
	mov eax,one_value
	add eax,two_value
	}
}



int main()
{
	int a;
	a = Make_Sum(1, 3);
}

