#include <stdio.h>
#include <stdlib.h>

struct Food
{
    int price;
    struct Food * next;
}*head = NULL, *tail = NULL;

struct Food *createFood(int price)
{
    struct Food *food = (struct Food*) malloc (sizeof(struct Food));
    food->price = price;
    food->next = NULL;
}

void pushHead(int price)
{
    struct Food *newFood = createFood(price);

    if(head == NULL)
    {
        head = tail = newFood;
    }
    else
    {
        newFood->next = head; // data baru nunjuk ke head
        head = newFood; // headnya dipundah ke data baru
    }
}

void pushTail(int price)
{
    struct Food *newFood = createFood(price);

    if(head == NULL)
    {
        head = tail = newFood; // data baru langsung jadi head dan tail
    }
    else
    {
        tail->next = newFood;
        tail = newFood;
    }
    return;
}

void printFood()
{
    struct Food *curr = head;
    while(curr != NULL)
    {
        printf("%d ", curr->price);
        curr = curr->next;
    }
}

void pushMid(int price)
{
    if(head == NULL || price < head->price)
    {
        pushHead(price);
    }
    else if(price >= tail->price)
    {
        pushTail(price);
    }
    else
    {
        struct Food *newFood = createFood(price);
        struct Food *curr = head;

        // looping jalan untuk cari tempat push
        while(curr->next != NULL && curr->next->price < price)
        {
            curr = curr->next;
        }

        newFood->next = curr->next; // nunjuk data baru sebelah current
        curr->next = newFood;
    }
}

void popHead()
{
    if(head == NULL)
    {
        return;
    }
    else if(head == tail)
    {
        
    }
}

int main()
{
    pushHead(23000);
    pushHead(17000);
    pushTail(30000);
    pushTail(25000);
    pushMid(19000);
    pushMid(49000);
    printFood();

    return 0;
}