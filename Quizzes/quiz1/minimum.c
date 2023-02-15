//1. You are given an array of integers (which can be positive or negative). You want to find the smallest integer in this array. If the array is empty, return 0; otherwise return the smallest value. 

int Minimum(int *array, int size)
{
    int min = 0;
    if (size == 0)
    {
        return 0;
    }
    else
    {
        min = array[0];
        for (int i = 1; i < size; i++)
        {
            if (array[i] < min)
            {
                min = array[i];
            }
        }
        return min;
    }
}