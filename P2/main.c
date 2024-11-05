#include <stdio.h>
#include <stdint.h>

uint8_t *extract_payload(uint8_t *data, int *payload_size);

uint8_t *extract_payload(uint8_t *data, int *payload_size)
{

    if(data == NULL)
    {
        return NULL;
    }

    *payload_size= (data[2]<<8 | data[3])- 1;


    if(*payload_size<=0)
    {
        return NULL;
    }

    uint8_t *payload= malloc(*payload_size * sizeof(uint8_t));

    for(int i= 0; i< *payload_size; i++)
    {

        payload[i]= data[i+ 5];
        printf("%d ", (int)payload[i]);
    }
    printf("\n");

    return payload;
}

int main(void)
{

//custom data to check if working

    uint8_t data[]= {0, 2, 0, 11,1,1,2,3,4,5,6,7,8,9,10};
    uint8_t payload_size= 0;

    uint8_t* payload= extract_payload(data, &payload_size);

    return 0;

}
