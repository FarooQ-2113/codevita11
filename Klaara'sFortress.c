#include <stdio.h>
#include <stdbool.h>

#define MAX_M 20
#define MAX_N 20

typedef struct
{
    int x;
    int y;
} Point;

typedef struct
{
    Point array[MAX_M * MAX_N];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

bool isEmpty(Queue *q)
{
    return q->front == -1;
}

void enqueue(Queue *q, Point p)
{
    if (isEmpty(q))
    {
        q->front = 0;
        q->rear = 0;
    }
    else
    {
        q->rear++;
    }
    q->array[q->rear] = p;
}

Point dequeue(Queue *q)
{
    Point p = q->array[q->front];
    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->front++;
    }
    return p;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int maxThiefTime(int m, int n, int fortress[MAX_M][MAX_N])
{
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int maxTime = 0;

    int bfs(int start_x, int start_y)
    {
        bool visited[MAX_M][MAX_N] = {false};
        int distance[MAX_M][MAX_N] = {0};
        Queue q;
        initQueue(&q);

        Point start = {start_x, start_y};
        enqueue(&q, start);
        visited[start_x][start_y] = true;

        while (!isEmpty(&q))
        {
            Point p = dequeue(&q);
            for (int i = 0; i < 4; i++)
            {
                int nx = p.x + directions[i][0];
                int ny = p.y + directions[i][1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny] && fortress[nx][ny] == 0)
                {
                    distance[nx][ny] = distance[p.x][p.y] + 1;
                    visited[nx][ny] = true;

                    Point newPoint = {nx, ny};
                    enqueue(&q, newPoint);
                }
            }
        }

        return distance[m - 1][n - 1];
    }

    int distance = bfs(0, 0);
    maxTime = distance;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (fortress[i][j] == 0)
            {
                fortress[i][j] = 1;
                distance = bfs(0, 0);
                maxTime = max(maxTime, distance);
                fortress[i][j] = 0;
            }
        }
    }

    return maxTime + 1;
}

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);

    int fortress[MAX_M][MAX_N];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &fortress[i][j]);
        }
    }

    int result = maxThiefTime(m, n, fortress);
    printf("%d", result);

    return 0;
    getch();
}
