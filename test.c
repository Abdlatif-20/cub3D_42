/*
	Write a C program that reads a date in the format 09/15/2012 
	and displays it in the following format: 15-September-2012.
*/

// # include <stdio.h>
// # include <stdlib.h>

// int main()
// {
//     char str[11];
//     int day;
//     int years;
// 	char *month;
// 	char months[20][12] = {"January", "February", "March", "April", "May",
// 							"June", "july", "August", "September", "October",
// 							"November", "December"};
//     scanf("%s", str);
// 	int	i = 0;
// 	int	flag = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == '/')
// 		{
// 			if (flag == 0)
// 			{
// 				month = months[atoi(str) - 1];
// 				flag++;
// 				i += 1;
// 			}
// 			if (flag == 1)
// 			{
// 				day = atoi(&str[i]);
// 				flag++;
// 				i+=3;
// 			}
// 			if (flag == 2)
// 			{
// 				years = atoi(&str[i]);
// 				flag++;
// 			}
// 		}
// 		i++;
// 	}
// 	printf("%d-%s-%d\n", day, month, years);
// }
