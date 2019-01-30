int max(int x, int y)
{
    if(x > y) return x;
    else return y;
}

int tri(int x, int y, int z)
{
    int r = x;
    if(y > r) r = y;
    if(z > r) r = z;
    return r;    
}

int sum(int x)
{
    int i, r;
    r = 0;
    for(i=0; i<=x; i++) {
	r += i;
    }
    return r;
}

int range(int s, int e)
{
    int i, r;
    r = 0;
    for(i=s; i<=e; i++) {
	r += i;
    }
    return r;
}
