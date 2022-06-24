#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>

int lv;
int lh;
int ls;
int sqdict[3] = {0, 0, 0};

int printsq(int *sq, int x, int y)
{
    for(int i = 0; i < y; i++)
    {
        for(int j = 0; j < x; j++)
        {
            printf("%d ", *(sq + (i * x) + j));
        }
        printf("\n");
    }
}
int printarr(int *arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", *(arr + i));
    }
    printf("\n");
    return 0;
}
int Iffin(int *resultlist, int size)
{   
    int res = 1;
    for(int i = 0; i < size; i++)
    {
        if(!*(resultlist + i))
        {
            res = 0;
            break;
        }
    }
    return res;
}
int Intersection(int *x, int *y, int size)
{
    for(int i = 0; i < size; i++)
    {
        if(*(x+i) * *(y+i) != 1)
        {
            *(x+i) = 0;
        }
    }
}

int Same(int *x, int *y, int size)
{
    int i;
    int res = 1;
    for(i = 0; i < size; i++)
    {
        if(*(x+i) != *(y+i))
        {
            res = 0;
            break;
        }
    }
    return res;
}

int Reversearr(int *x, int *y, int size)
{
    for(int i = 0; i < size; i++)
    {
        *(x+i) = *(y+size-1-i);
    }

    return 0;
}

int Copyarr(int *x, int *y, int size)
{
    for(int i = 0; i < size; i++)
    {
        *(x+i) = *(y+i);
    }
    return 0;
}

int Verify(int *x, int size, int *y, int *ysize)
{
    int status = 0;
    int index = -1;
    /*
    for (int i = 0;i < size;i++)
    {
        printf("%d", x[i]);
    }
    printf("\n");
    */
    for (int i = 0;i < size;i++)
    {
        if (*(x+i) == 1)
        {
            if (!status)
            {
                index++;
                *(y+index) = 1;
            }
            else
            {
                *(y+index) += 1;
            }
            status = 1;
        }
        else
        {
            status = 0;
        }
    }
    index++;
    *ysize = index;
    *(y+index) = 0;
    return 0;
}

int Pop(int *now, int lennow, int *x, int *y)
{
    int *startlist = (int *)malloc(sizeof(int) * lennow);
    int i, j;
    for(i = 0; i < lennow; i++)
    {
        *(startlist + i) = 0;
    }
    int a = 0;
    for(i = 0; i < lennow; i++)
    {
        if (*(now + i))
        {
            *(startlist + a) = *(now + i);
            a++;
        }
        else
        {
            break;
        }
    }
    while(1)
    {
        if(a > 0)
        {
            if(*(startlist + a - 1) == 1)
            {
                a--;
            }
            else
            {
                break;
            }

        }
        else
        {
            *x = 0;
            *y = 0;
            return 0;
        }
    }
    int status = 0;
    int m = 0;
    for(i = 0; i < a; i++)
    {
        if(*(startlist+i) == 1)
        {
            if(!status)
            {
                m++;
            }
            status = 1;
        }
        else
        {
            status = 0;
        }
    }
    *x = m;
    *y = a;
    free(startlist);
    return 0;
}

int Sequence2(int ***h, int ***v, int **s)
{
    int **res = (int **)malloc(sizeof(int *) * ls);
    int **result = (int **)malloc(sizeof(int *) * ls);
    int **xlist = (int **)malloc(sizeof(int *) * ls);
    int **blist = (int **)malloc(sizeof(int *) * ls);
    int i, j;
    int bcount = 0;
    for(i = 0; i < lh; i++)
    {
        *(res + i) = (int *)malloc(sizeof(int)*4);
        if(*(*(*(h+i)+1)) == 0)
        {
            *(*(res + i)) = 1;
            *(*(res + i)+1) = i;
            *(*(res + i)+2) = 0;
            *(*(res + i)+3) = 0;
        }
        else
        {
            int sum = -1;
            int M = 0;
            int b = 0;

            for(j = 0; j < *(*(*(h+i)+1)); j++)
            {
                int p = *(*(*(h+i)+0)+j);
                sum += p;
                sum += 1;
                if(p > M)
                {
                    M = p;
                    /*memcpy(&M, &p, 1);*/
                }
            }
            if((lv - sum) < M)
            {
                b = 1;
                bcount++;
            }

            *(*(res + i)) = 1;
            *(*(res + i)+1) = i;
            *(*(res + i)+2) = lv * *(*(*(h+i)+1)) - sum;
            *(*(res + i)+3) = b;          
        }
    }
    for(i = lh; i < lh+lv; i++)
    {
        *(res + i) = (int *)malloc(sizeof(int)*4);
        if(*(*(*(v+i-lh)+1)) == 0)
        {
            *(*(res + i)) = 0;
            *(*(res + i)+1) = i-lh;
            *(*(res + i)+2) = 0;
            *(*(res + i)+3) = 0;
        }
        else
        {
            int sum = -1;
            int M = 0;
            int b = 0;

            for(j = 0; j < *(*(*(v+i-lh)+1)); j++)
            {
                int p = *(*(*(v+i-lh)+0)+j);
                sum += p;
                sum += 1;
                if(p > M)
                {
                    M = p;
                    /*memcpy(&M, &p, 1);*/
                }
            }
            if((lh - sum) < M)
            {
                b = 1;
                bcount++;
            }

            *(*(res + i)) = 0;
            *(*(res + i)+1) = i-lh;
            *(*(res + i)+2) = lh * *(*(*(v+i-lh)+1)) - sum;
            *(*(res + i)+3) = b;          
        }
    }
    /*
    for(i = 0; i < lv + lh; i++)
    {
        for(j = 0; j < 4; j++)
        {
            printf("%d ", *(*(res + i)+j));
        }
        printf("\n");
    }
    */
    int m = 0;
    int mcount = 0;
    while(mcount < lv + lh)
    {
        for(i = 0; i < lv + lh; i++)
        {
            if(*(*(res + i)+2) == m)
            {
                *(result + mcount) = (int *)malloc(sizeof(int)*4);
                for(j = 0; j < 4; j++)
                {
                    *(*(result + mcount)+j) = *(*(res + i)+j);
                }
                mcount++;
                if(mcount == lv + lh)
                {
                    break;
                }
            }
        }
        m++;
    }
    bcount = 0;
    int xsize = 0;
    for(i = 0; i < ls; i++)
    {
        if(*(*(result + i)+3))
        {
            *(blist + bcount) = (int *)malloc(sizeof(int)*4);
                for(j = 0; j < 4; j++)
                {
                    *(*(blist + bcount)+j) = *(*(result + i)+j);
                }
                bcount++;            
        }
        else
        {
            *(xlist + xsize) = (int *)malloc(sizeof(int)*4);
                for(j = 0; j < 4; j++)
                {
                    *(*(xlist + xsize)+j) = *(*(result + i)+j);
                }
                xsize++;
        }
    }
    /*
    for(i = 0; i < lv + lh; i++)
    {
        for(j = 0; j < 4; j++)
        {
            printf("%d ", *(*(result + i)+j));
        }
        printf("\n");
    }
    */
    for(i = 0; i < bcount; i++)
    {
        for(j = 0; j < 4; j++)
        {
            *(*(s + i)+j) = *(*(blist + i)+j);
        }
    }
    for(i = 0; i < xsize; i++)
    {
        for(j = 0; j < 4; j++)
        {
            *(*(s + i + bcount)+j) = *(*(xlist + i)+j);
        }
    }
    for(i = 0; i < ls; i++)
    {
        free(*(res+i));
        free(*(result+i));
    }
    for(i = 0; i < bcount; i++)
    {
        free(*(blist+i));
    }
    for(i = 0; i < xsize; i++)
    {
        free(*(xlist+i));
    }

    free(blist);
    free(xlist);
    free(res);
    free(result);
    return 0;
}


int Logic(int *orig, int *now, int size, int *logic, int lsize, int num, int start, int num2, int end, int *resultlist, int *first, int side)
{
    int i, j, k;
    /*
    printarr(now, size);
    printarr(logic, lsize);
    printf("%d %d %d %d\n", num, start, num2, end);
    */
    if(*first&&Same(now, resultlist, size))
    {
        return 0;
    }
    for(i = start; i < size; i++)
    {
        if(*(now+i) == -1)
        {
            start++;
        }
        else
        {
            break;
        }
    }
    for(i = size - 1 - end; i >= 0; i--)
    {
        if(*(now+i) == -1)
        {
            end++;
        }
        else
        {
            break;
        }        
    }

    if(!*logic)
    {
        for(i = 0; i < size; i++)
        {
            *(resultlist + i) = -1;
        }
    }
    else
    {
        int p = size/2 + 1;
        int *Vn = (int *)malloc(sizeof(int) * p);
        int *Vnsize = (int *)malloc(sizeof(int));
        Verify(now, size, Vn, Vnsize);
        if((lsize == *Vnsize)&&Same(Vn, logic, lsize))
        {
            int *res = (int *)malloc(sizeof(int) * size);
            Copyarr(res, now, size);            
            for(i = 0; i < size; i++)
            {
                if(*(res+i) == 0)
                {
                    *(res+i) = -1;
                }
            }
            int errr = 0;
            for(i = 0; i < size; i++)
            {
                if(*(orig+i)&&(*(orig+i)!=*(res+i)))
                {
                    errr = 1;
                    break;
                }
            }
            if(!errr)
            {
                if(*first)
                {
                    Intersection(resultlist, res, size);
                }
                else
                {
                    Copyarr(resultlist, res, size);
                    *(first) = 1;
                }
            }
            free(res);
        }
        else
        {
            int notZero = 0;
            for(i = start; i < size - end; i++)
            {
                if(*(now+i))
                {
                    notZero = 1;
                    break;
                }
            }

            if(!notZero)
            {
                int *res = (int *)malloc(sizeof(int) * size);
                Copyarr(res, now, size);
                int sum = -1;
                int M = 0;
                int n = 0;
                for(i = num; i < lsize - num2; i++)
                {
                    int p = *(logic+i);
                    sum++;
                    if(p > M)
                    {
                        M = p;
                    }
                    sum += p;
                    n++;
                }
                int lse = size - end - start - sum;

                if((lse >= 0))
                {
                    if(M > lse)
                    {
                        int k = -1;

                        for(i = num; i < lsize - num2; i++)
                        {
                            k++;
                            int p = *(logic+i);
                            if(p > lse)
                            {
                                for(j = start+k+lse; j < start + k + p; j ++)
                                {
                                    *(res+j) = 1;
                                }
                            }
                            k += p;
                        }
                    }


                    int errr = 0;
                    for(i = 0; i < size; i++)
                    {
                        if(*(orig+i)&&(*(orig+i)!=*(res+i)))
                        {
                            errr = 1;
                            break;
                        }
                    }

                    if(!errr)
                    {
                        if(*first)
                        {
                            Intersection(resultlist, res, size);
                        }
                        else
                        {
                            Copyarr(resultlist, res, size);
                            *(first) = 1;
                        }
                    }                    
                }
                free(res);
            }
            else
            {
                int snxt = 0;
                int enxt = 0;

                for(i = start; i < size; i++)
                {
                    if(!*(now+i))
                    {
                        snxt++;
                    }
                    else
                    {
                        break;
                    }
                }
                for(i = end; i < size; i++)
                {
                    if(!*(now+size-1-i))
                    {
                        enxt++;
                    }
                    else
                    {
                        break;
                    }
                }

                int *aorig = (int *)malloc(sizeof(int) * size);
                int *anow = (int *)malloc(sizeof(int) * size);
                int *alogic = (int *)malloc(sizeof(int) * lsize);
                int reverse = 0;
                if((((snxt <= enxt)&&(!*(now + size - end - 1)))&&(side == 0))||(side == 1))
                {
                    Copyarr(aorig, orig, size);
                    Copyarr(anow, now, size);
                    Copyarr(alogic, logic, lsize);
                }
                else
                {
                    Reversearr(aorig, orig, size);
                    Reversearr(anow, now, size);
                    Reversearr(alogic, logic, lsize);
                    int ppp = start;
                    start = end;
                    end = ppp;
                    ppp = num;
                    num = num2;
                    num2 = ppp;
                    reverse = 1;
                }
                if(*(anow+start) == 1)
                {
                    int *res = (int *)malloc(sizeof(int) * size);
                    Copyarr(res, anow, size);        
                    for(i = start; i < start + *(alogic + num); i++)
                    {
                        *(res+i) = 1;
                    }
                    if(*(alogic+num) < size-start)
                    {
                        *(res + start + *(alogic + num)) = -1;
                    }
                    if(num + num2 + 1 == lsize)
                    {
                        for(i = 0; i < size; i++)
                        {
                            if(!*(res + i))
                            {
                                *(res + i) = -1;
                            }
                        }
                        int errr = 0;
                        for(i = 0; i < size; i++)
                        {
                            if(*(aorig+i)&&(*(aorig+i)!=*(res+i)))
                            {
                                errr = 1;
                                break;
                            }
                        }
                        int p = size/2 + 1;            
                        int *Vn = (int *)malloc(sizeof(int) * p);
                        int *Vnsize = (int *)malloc(sizeof(int));
                        Verify(res, size, Vn, Vnsize);
                        if(!((lsize == *Vnsize)&&Same(Vn, alogic, lsize)))
                        {
                            errr = 1;
                        }
                        if(!errr)
                        {
                            if(*first)
                            {
                                if(reverse)
                                {
                                    int *Rres = (int *)malloc(sizeof(int) * size);
                                    Reversearr(Rres, res, size);
                                    Intersection(resultlist, Rres, size);
                                    free(Rres);
                                }
                                else
                                {
                                    Intersection(resultlist, res, size);
                                }
                            }
                            else
                            {
                                if(reverse)
                                {
                                    int *Rres = (int *)malloc(sizeof(int) * size);
                                    Reversearr(Rres, res, size);
                                    Copyarr(resultlist, Rres, size);
                                    free(Rres);                        
                                }
                                else
                                {
                                    Copyarr(resultlist, res, size);
                                }
                                *(first) = 1;
                            }
                        }
                        free(Vn);
                        free(Vnsize);        
                    }

                    else
                    {
                        int errr = 0;
                        for(i = 0; i < size; i++)
                        {
                            if(*(aorig+i)&&(*(aorig+i)!=*(res+i)))
                            {
                                errr = 1;
                                break;
                            }
                        }
                        if(!errr)
                        {
                            int nstart = start + *(alogic+num) + 1;
                            int nnum = num + 1;
                            if(reverse)
                            {
                                int *Rorig = (int *)malloc(sizeof(int) * size);
                                int *Rres = (int *)malloc(sizeof(int) * size);
                                int *Rlogic = (int *)malloc(sizeof(int) * lsize);
                                Reversearr(Rorig, aorig, size);
                                Reversearr(Rres, res, size);
                                Reversearr(Rlogic, alogic, lsize);
                                Logic(Rorig, Rres, size, Rlogic, lsize, num2, end, nnum, nstart, resultlist, first, side);
                                free(Rorig);
                                free(Rres);
                                free(Rlogic);                        
                            }
                            else
                            {
                                Logic(aorig, res, size, alogic, lsize, nnum, nstart, num2, end, resultlist, first, side);
                            }
                        }            
                    }
                    free(res);
                }
                else
                {
                    int en = -1;
                    if(lsize > num + num2)
                    {
                        for(i = num; i < lsize - num2; i++)
                        {
                            en += *(alogic+i) + 1;
                        }
                    }
                    for(j = start; j < size - end + 1 - en; j++)
                    {
                        int *res = (int *)malloc(sizeof(int) * size);
                        Copyarr(res, anow, size);
                        int a = j - 1;
                        int b = j + *(alogic+num);
                        int err = 0;
                        if((a != -1)&&(*(res+a) == 1))
                        {
                            break;
                        }
                        for(k = start; k < a + 1; k++)
                        {
                            if(*(res+k) == 1)
                            {
                                err = 1;
                                break;
                            }
                            else
                            {
                                *(res+k) = -1;
                            }
                        }
                        if(err)
                        {
                            continue;
                        }
                        if(b != size)
                        {
                            if(*(res+b) == 1)
                            {
                                err = 1;
                            }
                            else
                            {
                                *(res+b) = -1;
                            }
                        }
                        if(err)
                        {
                            continue;
                        }
                        for(k = j; k < j + *(alogic+num); k++)
                        {
                            if(*(res+k) != -1)
                            {
                                *(res+k) = 1;
                            }
                            else
                            {
                                err = 1;
                                break;
                            }
                        }
                        if(err)
                        {
                            continue;
                        }
                        if(num + num2 + 1 == lsize)
                        {
                            for(i = 0; i < size; i++)
                            {
                                if(!*(res + i))
                                {
                                    *(res + i) = -1;
                                }
                            }
                            int errr = 0;
                            for(i = 0; i < size; i++)
                            {
                                if(*(aorig+i)&&(*(aorig+i)!=*(res+i)))
                                {
                                    errr = 1;
                                    break;
                                }
                            }
                            int p = size/2 + 1;            
                            int *Vn = (int *)malloc(sizeof(int) * p);
                            int *Vnsize = (int *)malloc(sizeof(int));
                            Verify(res, size, Vn, Vnsize);
                            if(!((lsize == *Vnsize)&&Same(Vn, alogic, lsize)))
                            {
                                errr = 1;
                            }
                            if(!errr)
                            {
                                if(*first)
                                {
                                    if(reverse)
                                    {
                                        int *Rres = (int *)malloc(sizeof(int) * size);
                                        Reversearr(Rres, res, size);
                                        Intersection(resultlist, Rres, size);
                                        free(Rres);
                                    }
                                    else
                                    {
                                        Intersection(resultlist, res, size);
                                    }
                                }
                                else
                                {
                                    if(reverse)
                                    {
                                        int *Rres = (int *)malloc(sizeof(int) * size);
                                        Reversearr(Rres, res, size);
                                        Copyarr(resultlist, Rres, size);
                                        free(Rres);                        
                                    }
                                    else
                                    {
                                        Copyarr(resultlist, res, size);
                                    }
                                    *(first) = 1;
                                }
                            }
                            free(Vn);
                            free(Vnsize);     
                        }
                        else
                        {
                            int errr = 0;
                            for(i = 0; i < size; i++)
                            {
                                if(*(aorig+i)&&(*(aorig+i)!=*(res+i)))
                                {
                                    errr = 1;
                                    break;
                                }
                            }
                            if(!errr)
                            {
                                
                                int nstart  = j + *(alogic+num) + 1;

                                int nnum = num + 1;

                                if(reverse)
                                {
                                    int *Rorig = (int *)malloc(sizeof(int) * size);
                                    int *Rres = (int *)malloc(sizeof(int) * size);
                                    int *Rlogic = (int *)malloc(sizeof(int) * lsize);
                                    Reversearr(Rorig, aorig, size);
                                    Reversearr(Rres, res, size);
                                    Reversearr(Rlogic, alogic, lsize);
                                    if(side == 2)
                                    {
                                        if(*first)
                                        {
                                            Intersection(resultlist, Rres, size);
                                        }
                                        else
                                        {
                                            Copyarr(resultlist, Rres, size);
                                            *(first) = 1;
                                        }
                                    }
                                    else
                                    {
                                        Logic(Rorig, Rres, size, Rlogic, lsize, num2, end, nnum, nstart, resultlist, first, side);
                                    }
                                    free(Rorig);
                                    free(Rres);
                                    free(Rlogic);
                                }
                                else
                                {
                                    if(side == 1)
                                    {
                                        side++;
                                    }
                                    Logic(aorig, res, size, alogic, lsize, nnum, nstart, num2, end, resultlist, first, side);
                                }


                            }            
                        }
                        free(res);
                    }
                }
                free(aorig);
                free(anow);
                free(alogic);
            }
        }
        free(Vn);
        free(Vnsize);
    }
    return 0;
}


int Solution2(int **arr, int size, int m, int*square, int ***h, int ***v, int **s, int side)
{
    int i, j;
    int **new_sequence = (int **)malloc(sizeof(int*) * size);
    for(i = 0; i < size; i++)
    {

        *(new_sequence + i) = (int *)malloc(sizeof(int) * 2);
    }
    int lns = 0;
    for(i = 0; i < m + 1; i ++)
    {
        for(j = 0; j < size; j++)
        {
            if((*(*(s+i)) == *(*(arr+j)))&&*(*(s+i)+1) == *(*(arr+j)+1))
            {
                *(*(new_sequence + lns)) = *(*(s+i));
                *(*(new_sequence + lns)+1) = *(*(s+i)+1);
                lns++;
            }
        }
    }

    for(i = 0; i < lns; i++)
    {
        /*printf("%d %d\n", *(*(new_sequence + i)), *(*(new_sequence + i)+1));*/
        int boo = *(*(new_sequence + i));
        int num = *(*(new_sequence + i)+1);
        int **seq = (int **)malloc(sizeof(int*) * 3);
        if(boo)
        {
            *(seq+1) = (int *)malloc(sizeof(int));
            *(*(seq+1)) = *(*(*(h + num)+1));

            *(seq+2) = (int *)malloc(sizeof(int));
            *(*(seq+2)) = *(*(*(h + num)+2));

            *seq = (int *)malloc(sizeof(int) * *(*(seq+1)));
            for(j = 0; j < *(*(seq+1)); j++)
            {
                *(*(seq) + j) = *(*(*(h + num))+j);
            }
        }
        else
        {
            *(seq+1) = (int *)malloc(sizeof(int));
            *(*(seq+1)) = *(*(*(v + num)+1));

            *(seq+2) = (int *)malloc(sizeof(int));
            *(*(seq+2)) = *(*(*(v + num)+2));

            *seq = (int *)malloc(sizeof(int) * *(*(seq+1)));
            for(j = 0; j < *(*(seq+1)); j++)
            {
                *(*(seq) + j) = *(*(*(v + num))+j);
            }
        }
        /*
        for(j = 0; j < *(*(seq+1)); j++)
        {
            printf("%d ", *(*(seq) + j));
        }
        printf("%d %d\n", *(*(seq+1)), *(*(seq+2)));
        */
        if(!*(*(seq+2)))
        {
            /*
            printf("boo, num = %d %d\n", boo, num);
            */
            int *now;
            int fin = 0;
            int size;
            if(boo)
            {   
                now = (int *)malloc(sizeof(int) * lv);
                for(j = 0; j < lv; j++)
                {
                    *(now + j) = *(square + (lv * num) + j);
                    if(!*(now + j))
                    {
                        fin++;
                    }
                }
                size = lv;
            }
            else
            {
                now = (int *)malloc(sizeof(int) * lh);

                for(j = 0; j < lh; j++)
                {
                    *(now + j) = *(square + num + (j * lv));
                    if(!*(now + j))
                    {
                        fin++;
                    }
                }
                size = lh;
            }
            if(!fin)
            {
                if(boo)
                {
                    *(*(*(h + num)+2)) = 1;
                }
                else
                {
                    *(*(*(v + num)+2)) = 1;
                }
                continue;
            }

            int *resultlist = (int *)malloc(sizeof(int) * size);
            Copyarr(resultlist, now, size);
            int s1, s2, e1, e2;
            Pop(now, size, &s1, &s2);
            int *reversenow = (int *)malloc(sizeof(int) * size);
            Reversearr(reversenow, now, size);
            Pop(reversenow, size, &e1, &e2);
            free(reversenow);
            int *first = (int *)malloc(sizeof(int));
            *first = 0;
            Logic(now, now, size, *(seq), *(*(seq+1)), s1, s2, e1, e2, resultlist, first, side);
            free(first);
            /*
            printarr(resultlist, size);
            */
            if(!Same(resultlist, now, size))
            {
                int **dif = (int **)malloc(sizeof(int *) * size);
                for(j = 0; j < size; j++)
                {
                    *(dif+j) = (int *)malloc(sizeof(int) * 2);
                }
                int difsize = 0;
                for(j = 0; j < size; j++)
                {
                    if(*(now+j) != *(resultlist+j))
                    {
                        *(*(dif + difsize)) = !boo;
                        *(*(dif + difsize)+1)= j;
                        difsize++;
                    }
                }
                if(Iffin(resultlist, size))
                {
                    if(boo)
                    {
                        *(*(*(h + num)+2)) = 1;
                    }
                    else
                    {
                        *(*(*(v + num)+2)) = 1;
                    }
                }
                if(boo)
                {
                    for(j = 0; j < lv; j++)
                    {
                        *(square+(num*lv)+j) = *(resultlist + j);
                    }
                }
                else
                {
                    for(j = 0; j < lh; j++)
                    {
                        *(square + num + (j*lv)) = *(resultlist + j);
                    }
                }
                int nowdict[3] = {0, 0, 0};
                int resdict[3] = {0, 0, 0};

                for(j = 0; j < size; j++)
                {
                    nowdict[*(now + j) + 1]++;                    
                    resdict[*(resultlist + j) + 1]++;
                }
                for(j = 0; j < 3; j++)
                {
                    sqdict[j] = sqdict[j] - nowdict[j] + resdict[j];
                }
                float pct = (sqdict[0] + sqdict[2]) * 10000 / (lv * lh);
                wprintf(L"□ : %d Ⅹ : %d ■ : %d\n", sqdict[1], sqdict[0], sqdict[2]);
                printf("%.2f%%\n", pct / 100);

                /*
                printsq(square, lv, lh);
                */
                Solution2(dif, difsize, ls - 1, square, h, v, s, 1);
                if(!side)
                {
                    Solution2(dif, difsize, m, square, h, v, s, 0);
                }
                for(j = 0; j < size; j++)
                {
                    free(*(dif+j));
                }
                free(dif);
            }
            free(resultlist);
            free(now);
        }
        for(int k = 0; k < 3; k++)
        {
            free(*(seq+k));
        }
        free(seq);
    }
    for(i = 0; i < size; i++)
    {
        free(*(new_sequence + i));
    }
    free(new_sequence);
    return 0;
}

int Solution(int ***h, int ***v, int **s)
{
    int *square = (int *)malloc(sizeof(int) * lv * lh);
    *(sqdict + 1) = lv * lh;
    int i, j, m;
    for(i = 0; i < lv * lh; i++)
    {
        *(square + i) = 0;
    }

    Solution2(s, ls, ls - 1, square, h, v, s, 1);
    /*
    printsq(square, lv, lh);
    */
    int *lastsquare = (int *)malloc(sizeof(int) * lv * lh);

    while(1)
    {
        for(m = 0; m < ls; m++)
        {
            Solution2(s+m, 1, m, square, h, v, s, 0);
        }
        int notsame = 0;
        for(i = 0; i < lv * lh; i++)
        {
            if(*(lastsquare + i) != *(square + i))
            {
                notsame++;
            }
        }
        if(notsame)
        {
            for(i = 0; i < lv * lh; i++)
            {
                *(lastsquare + i) = *(square + i);
            }            
        }
        else
        {
            break;
        }

    }

    for(int i = 0; i < lh; i++)
    {
        for(int j = 0; j < lv; j++)
        {
            if(*(square + (i * lv) + j) == 1)
            {
                wprintf(L"■ ");                
            }
            else
            {
                if(*(square + (i * lv) + j) == -1)
                {
                    wprintf(L"Χ ");
                }          
                else
                {
                    wprintf(L"□ ");
                }      
            }
            if(j%5 == 4)
            {
                printf(" ");
            }
        }
        printf("%d\n", i);
        if(i%5 == 4)
        {
            printf("\n");
        }
    }

    free(square);
    free(lastsquare);

    return 0;
}
int main(void)
{
    setlocale(LC_ALL, "");
    FILE *fp;
    wprintf(L"Made by Arat(https://arat5724.tistory.com/ 에서만 다운받으세요.)\n파일 이름을 입력하세요.(.txt 제외) : ");
    char x[10];
    scanf("%s", x);
    strcat(x, ".txt");
    fp= fopen(x, "r");
    int logichome[18];
    char lenh[4] = {0, 0, 0, 0};
    char lenv[4] = {0, 0, 0, 0};
    int c;
    int i = 0;
    int j = 0;
    int num = 0;

    while(((c = fgetc(fp)) != EOF))
    {
        if(c == '\n')
        {
            if(num<2)
            {
                num++;
                i = 0;
            }
            else
            {
                break;
            }
        }
        else
        {
            if(num == 0)
            {
                logichome[i] = c;
            }
            else
            {
                if(num == 1)
                {
                    lenh[i] = c;
                }
                else
                {
                    lenv[i] = c;
                }
            }
            i++;
        }
    }
    lv = atoi(lenh);
    
    lh = atoi(lenv);
    ls = lv + lh;
    /*
    printf("%d\n%d\n", lv, lh);
    */
    int *row = (int *)malloc(lh*lv*sizeof(int));
    
    char d[2] = {' ', '\0'};

    for(i = 0; i < lh*lv; i++)
    {
        d[0] = fgetc(fp);
        *(row+i) = atoi(d);
    }
    /*
    for(i = 0; i < lh*lv; i++)
    {
        printf("%d", *(row+i));
    }
    */
    /*
    printf("\n");
    */
    fclose(fp);
    int ***horizontal = (int ***)malloc(sizeof(int**) * lh);
    for(i = 0; i < lh; i++)
    {
        *(horizontal+i) = (int**)malloc(sizeof(int*) * 3);
        int p = (lv / 2) + 1;
        *(*(horizontal+i)+0) = (int*)malloc(sizeof(int) * p);
        *(*(horizontal+i)+1) = (int*)malloc(sizeof(int));
        Verify(row+(i*lv), lv, *(*(horizontal+i)), *(*(horizontal+i)+1));
        *(*(horizontal+i)+2) = (int*)malloc(sizeof(int));
        *(*(*(horizontal+i)+2)) = 0;
    }
    int ***vertical = (int ***)malloc(sizeof(int**) * lv);
    for(i = 0; i < lv; i++)
    {
        *(vertical+i) = (int**)malloc(sizeof(int*) * 3);
        int p = (lh / 2) + 1;
        *(*(vertical+i)+0) = (int*)malloc(sizeof(int) * p);
        *(*(vertical+i)+1) = (int*)malloc(sizeof(int));
        int *varr = (int*)malloc(sizeof(int) * lh);
        for(j = 0; j < lh; j++)
        {
            *(varr + j) = *(row + i + (j * lv));
        }
        Verify(varr, lh, *(*(vertical+i)), *(*(vertical+i)+1));
        free(varr);
        *(*(vertical+i)+2) = (int*)malloc(sizeof(int));   
        *(*(*(vertical+i)+2)) = 0;
    }
    /*
    for(i = 0; i < lh; i++)
    {
        for(j = 0; j < *(*(*(horizontal+i)+1)); j++)
        {
            printf("%d, ", *(*(*(horizontal+i))+j));
        }
        printf("\n");
    }
    for(i = 0; i < lv; i++)
    {
        for(j = 0; j < *(*(*(vertical+i)+1)); j++)
        {
            printf("%d, ", *(*(*(vertical+i))+j));
        }
        printf("\n");
    }
    */
    int **sequence = (int**)malloc(sizeof(int*) * (lv+lh));
    for(i = 0; i < lv + lh; i++)
    {
        *(sequence + i) = (int*)malloc(sizeof(int) * 4);
    }

    Sequence2(horizontal, vertical, sequence);
    /*
    for(i = 0; i < lv + lh; i++)
    {
        for(j = 0; j < 4; j++)
        {
            printf("%d ", *(*(sequence + i)+j));
        }
        printf("\n");
    }
    */
    time_t seconds;
    time(&seconds);


    Solution(horizontal, vertical, sequence);
    
    time_t seconds2;
    time(&seconds2);
    float pct = (sqdict[0] + sqdict[2]) * 10000 / (lv * lh);
    wprintf(L"□ : %d Ⅹ : %d ■ : %d\n", sqdict[1], sqdict[0], sqdict[2]);
    printf("%.2f%%\n", pct / 100);
    wprintf(L"%d초\n", seconds2 - seconds);
    free(row);
    for(i = 0; i < lh; i++)
    {
        for(j = 0; j < 3; j++)
        {
            free(*(*(horizontal + i) + j));
        }
        free(*(horizontal + i));
    }
    free(horizontal);
    for(i = 0; i < lv; i++)
    {
        for(j = 0; j < 3; j++)
        {
            free(*(*(vertical + i) + j));
        }
        free(*(vertical + i));
    }
    free(vertical);
    for(i = 0; i < ls; i++)
    {
        free(*(sequence + i));
    }
    free(sequence);
    system("PAUSE");
    return 0;

}