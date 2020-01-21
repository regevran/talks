
struct A { bool f(); };

int f1( A* pa )
{
    if ( pa )
    {
        if ( pa->f() )
        {
            // more code
        }
    }
    return 0;
}

int f2( A* pa )
{
    if ( pa && pa->f() )
    {
        // more code
    }
    return 0;
}

int main()
{
    return 0;
}