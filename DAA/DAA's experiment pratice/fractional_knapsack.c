#include <stdio.h>

void main()
{
    int capacity, no_items, cur_weight, item;
    int used[10];
    float total_profit;
    int i;
    int weight[10];
    int value[10];

    printf("Enter the capacity of knapsack:\n");
    scanf("%d", &capacity);

    printf("Enter the number of items:\n");
    scanf("%d", &no_items);

    printf("Enter the weight and value of %d item:\n", no_items);
    for (i = 0; i < no_items; i++)
    {
        printf("Weight[%d]:\t", i);
        scanf("%d", &weight[i]);
        printf("Value[%d]:\t", i);
        scanf("%d", &value[i]);
    }
    // initially set the all value in used array is zero
    for (i = 0; i < no_items; ++i)
    {
        used[i] = 0;
    }
   /*sorting the value by weight it take O(nlogn)time*/
    cur_weight = capacity;
    while (cur_weight > 0) //current weight must be greater than zero to fill knapsack
    {
        item = -1;//means that item is not select
        for (i = 0; i < no_items; ++i)
        {
            if ((used[i] == 0) &&
                ((item == -1) || ((float)value[i] / weight[i] > (float)value[item] / weight[item])))
                item = i;// here ith element is selected.
        }

        used[item] = 1; // that item is selected
        cur_weight -= weight[item];//put that item in knapsack
        total_profit += value[item];//and get the profit by that item
        if (cur_weight >= 0) 
        {   // this code will execute when a full item is selected 
            printf("Added object %d (%d Rs., %dKg) completely in the bag. Space left: %d.\n", item + 1, value[item], weight[item], cur_weight);
        }
        else
        {   // when partial selection is occur this code will exicute
            int item_percent = (int)((1 + (float)cur_weight / weight[item]) * 100);
            printf("Added %d%% (%d Rs., %dKg) of object %d in the bag.\n", item_percent, value[item], weight[item], item + 1);
            total_profit -= value[item];
            total_profit += (1 + (float)cur_weight / weight[item]) * value[item];
        }
    }

    printf("Filled the bag with objects worth %.2f Rs.\n", total_profit);
}
