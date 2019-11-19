#include <stdio.h>
#include <string.h>

int main(void) {
	int i, j, keylen, msglen;
	char input[100], key[30], temp[30], quot[100], rem[30], key1[30];
	
	printf("Enter Data: ");
	scanf("%s", input);
	printf("Enter Key: ");
	scanf("%s", key);
	keylen = strlen(key);
	msglen = strlen(input);

	strcpy(key1, key);

	// appending zeroes at the end of the message
	for (i = 0; i < keylen - 1; ++i) {
		input[msglen + i] = '0';
	}
	input[msglen + i] = '\0';
	// printf("\nkey = %s\nkey1 = %s\nzero appended message = %s\n", key, key1, input);
	
	// taking first keylen bits of message in temp
	for(i = 0; i < keylen; ++i)
		temp[i] = input[i];
	temp[i] = '\0';
	// printf("\ntemp = %s\n", temp);	
	
	for(i = 0; i < msglen; ++i) {
		quot[i] = temp[0];
		if(quot[i] == '0')
			for(j = 0; j < keylen; ++j)
		 		key[j] = '0';
		else
			for(j = 0; j < keylen; ++j)
		 		key[j] = key1[j];
		// printf("\nkey = %s\nkey1 = %s\n", key, key1);
		for(j = keylen - 1; j > 0; --j) {
			if(temp[j] == key[j])
				rem[j - 1] = '0'; 
			else
				rem[j - 1] = '1';
		}
		rem[keylen - 1] = input[i + keylen];
		strcpy(temp, rem);
	}
	strcpy(rem, temp);

	printf("\nQuotient is ");
	for(i = 0; i < msglen; ++i)
		printf("%c", quot[i]);
	printf("\nRemainder is ");
	for(i = 0; i < keylen - 1; ++i)
		printf("%c", rem[i]);
	printf("\nFinal data is: ");
	for(i = 0; i < msglen; ++i)
		printf("%c", input[i]);
	for(i = 0; i < keylen - 1; ++i)
		printf("%c",rem[i]);
	return 0;
}