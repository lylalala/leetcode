static int mycmp(const void* param1, const void* param2) {
    struct Interval* p1 = (struct Interval*)param1;
    struct Interval* p2 = (struct Interval*)param2;
    return (p1->start - p2->start);
}

struct Interval* merge(struct Interval* intervals, int intervalsSize, int* returnSize) {
    if (!intervals || !intervalsSize) return NULL;
    int retSize = 0;
    struct Interval* ret = (struct Interval*)malloc(sizeof(struct Interval) * intervalsSize);
    if (ret) {
        struct Interval *p, *q, *end;
        qsort(intervals, intervalsSize, sizeof(struct Interval), mycmp);
        *ret = *intervals;
        for (p = ret, q = intervals + 1, end = intervals + intervalsSize; q < end; q++) {
            if (p->end >= q->start) {
                if (p->end < q->end) p->end = q->end;
            } else {
                *(++p) = *q;
            }
        }
        retSize = (int)(p - ret + 1);
    }
    if (returnSize) *returnSize = retSize;
    return ret;
}
