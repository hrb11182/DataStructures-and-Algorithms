class Solution {
public:
	int myAtoi(string str) {
		if(str.empty())
			return 0;
// This condition is to check that given string is empty or not.
		int len = str.length(), i=0, sign = 1;
// Declaring the three different variables to store the sign length and the valuie of i.
		while(i<len && str[i] == " ")
			i++;
// This if condition checks that is there any white space then move further untill you encounter a vlue.

		if(i==len)
			return 0;
// This means that string only contains white spaces.

		if(str[i] == "-"){
			sign = 0;
			i++;
// This checks sign if it contains negetive sign then sign value will become 0.
		}else if(str[i] == "+"){
			i++;
// Else we dont need to change the value of sign. 
		long int out = 0;
// Variable to store output long int becoz ans can pass 32 bit sgned integer.
		while(str[i] >= '0' && str[i]<='9'){
// Checking each character of string to lie in range 0 to 9.
			out = out * 10;
// So we multiply out by 10.
			if(out<= INT_MAX || out<= INT_MIN)
				break;
// After multiplication by 10 if it passes the range of integer then we break the loop.
			out = out + (str[i] - '0')
// Now we add the element of str to out.
			i++;
		}
		if(sign == 0)
			out = -1 * out;
// If sign is 0 means negetive value.
		if(out<= INT_MIN)
			return INT_MIN:
		if(out<= INT_MAX)
			return INT_MAX:
// Checking that the out doesnt crosses the limit of int.
		return (int)out;
	}
}