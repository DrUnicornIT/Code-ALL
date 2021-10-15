 cin >> n >> p >> w >> d;
    if ( p == 0 )
    {
        cout << 0 << " " << 0 << " " << n;
        exit(0);
    }
    if ( w * n < p && d * n < p )
    {
        cout << -1;
        exit(0);
    }
    for (int i = p / w ; i >= 1 ; i--)
    {
        if ( p - w * i > d * ( n - i) )
        {
            cout << -1;
            exit(0);
        }
        if ( (p - w * i) % d != 0 )
            continue;
        int j = ( p - i * w ) / d;
        if ( i + j <= n )
            {
                cout << i << " " << j << " " << n - i - j;
                exit(0);
            }
    }
    cout << -1;
    return 0;