/*

 *Different Ways of structure initialization

*/
#include <stdio.h>

#include <string.h>

#define NAME_LEN 25

typedef unsigned short age_t;

typedef unsigned int roll_t;

typedef struct student{

	char name[NAME_LEN];

	roll_t rno;

	age_t age;

}student;

int main()

{

	/* Method 3a: Just like the Method 2a, but here you do not

	 * need to know order of the elements in the declaration

	 */

	student st3={

		.name = "Mark",//Notice the equal to and comma

		.age  = 23,
		.rno  = 1038
	};

	printf("%s %hi %u\n\n",st3.name,st3.age,st3.rno);

	/*

	 * Method 3b: For Initializing an array of structures

	 */

	student st4[]={
		{

			.name = "Neil",

			.age  = 23,

			.rno  = 1039      },

		{

			.name = "Peter",

			.age  = 23,

			.rno  = 1040

		}
	};

	printf("%s %hi %u\n%s %hi %u\n\n",st4[0].name,st4[0].age,

			st4[0].rno, st4[1].name,st4[1].age,st4[1].rno);

	/*

	 * Method 3c : Change the order of initialization of the

	 * elements of the array. Normally as seen in Method 2b,

	 * the 0th array element is initialized  then 1st, then

	 * 2nd and so on. So by using a variation  of Method 3b,

	 * we  can initialize the array elements in any order

	 */

	student st5[5]={

		[3]={

			.name = "Titus",

			.age  = 22,

			.rno  = 1041      },

		[2]={

			.name = "Stephen",

			.age  = 23,

			.rno  = 1042

		}

		/*As you can see only 2nd and 3rd array elements has

		 * been initialized and that too not in order. Such

		 * an initialization is useful, if we wish to allocate

		 * some fixed size array but only initialize some element

		 */
	};

	printf("%s %hi %u\n%s %hi %u\n\n",st5[2].name,st5[2].age,

			st5[2].rno, st5[3].name,st5[3].age,st5[3].rno);

}
