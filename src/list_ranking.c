#include <list_ranking.h>

int write(Value32 *array, uint64_t index, uint64_t max_index, Value32 value)
{
    if (index > max_index) 
    {
        fprintf(stderr, "Index is above array maximum capacity\n");
        return -1;
    }
    array[index] = value;
    return 0;
}
int read(Value32 *array, uint32_t index, uint64_t max_index,  Value32 *dest)
{
    if (index > max_index)
    {
        fprintf(stderr, "Index is above array maximum capacity\n");
        return -1;
    }
    *dest = array[index];
    return 0;
}

int create_array(uint64_t size, Value32 *arr)
{
    Value32 *array = calloc(size, sizeof (Value32));
    if (array == NULL)
    {
        fprintf(stderr, "Cannot allocate memory\n");
        return -1;
    }
    arr = array;
    return 0;
}

int free_array(Value32 *arr)
{
    free(arr);
}

int set_int_value(Value32 *dest, void *value)
{
    if (dest == NULL)
    {
        fprintf(stderr, "Destination is NULL\n");
        return -1;
    }
    if (value == NULL)
    {
        (*dest).i = INT32_MIN;
        return 0;
    }
    (*dest).i = *(int32_t *)value;
    return 0;
}

int get_max_subarray(Value32 *arr, uint64_t start, uint64_t end, cmp_func cmp, setter_func set, Value32 *ret)
{
    if (end > start)
    {
        fprintf(stderr, "End index: %lu is greater than start index: %lu\n", end, start);
        return -1;
    }
    Value32 max;
    set(&max, NULL);
    for (uint64_t i=start; i <= end; i++)
    {
        if ((*cmp)(max, arr[i]) < 0)
        {
            set(&max, &(arr[i].i));
        }
    }
    *ret = max;
    return 0;
}

int get_max(Value32 *arr, Value32 *resp)
{

}
int main(){
    Value32 *resp;
    Value32 *values;

    create_array(500, values);

    populate_array(values);

    measure(&get_max, values, resp);

    free_array(resp);
    free_array(values);
    fprintf(stdout, "Hello world!");
    return 0;
}