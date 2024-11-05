#include <stdio.h>

#include <math.h>

int main() {

    int data[10];

    int data_at_reciever[10];

    int c,c1,c2,c3,i;


    printf("Enter 4 bits of data one by one\n");

    scanf("%d", &data[0]);

    scanf("%d", &data[1]);

    scanf("%d", &data[2]);

    scanf("%d", &data[4]);

    //Calculation of even parity

    data[6] = data[0] ^ data[2] ^ data[4];

    data[5] = data[0] ^ data[1] ^ data[4];

    data[3] = data[0] ^ data[1] ^ data[2];
    
     
 printf("\nEncoded data is\n");

    for (i = 0; i < 7; i++) {

        printf("%d ",data[i]);

    }



   printf("\nEnter received data bits one by one\n");

for (i = 0; i < 7; i++) {

    scanf("%d", &data_at_reciever[i]);

}



c1 = data_at_reciever[6] ^ data_at_reciever[4] ^ data_at_reciever[2] ^ data_at_reciever[0];

c2 = data_at_reciever[5] ^ data_at_reciever[4] ^ data_at_reciever[1] ^ data_at_reciever[0];

c3 = data_at_reciever[3] ^ data_at_reciever[2] ^ data_at_reciever[1] ^ data_at_reciever[0];

c = c3 * 4 + c2 * 2 + c1 ;



if(c == 0) {

    printf("No error while transmission of data\n");

}

else {

    printf("Error on position %d", c);    

    printf("\nData sent : ");

    for (i = 0; i < 7; i++) {

        printf("%d ", data[i]);

    }


    printf("\nData received : ");

    for (i = 0; i < 7; i++) {

        printf("%d ", data_at_reciever[i]);

    }


    printf("\nCorrect message is\n");


    //if errorneous bit is 0 we complement it else vice versa

    if(data_at_reciever[7-c] == 0) {

        data_at_reciever[7-c] = 1;

    }

    else {

        data_at_reciever[7-c] = 0;

    }

    for (i = 0; i < 7; i++) {

        printf("%d ",data_at_reciever[i]);

    }

}



return 0;

}
