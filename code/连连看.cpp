int remove(int x1, int y1, int x2, int y2)
{
	if(x1 == x2 && y1 == y2)
		return 1;
	//同一列
	else if(x1 == x2)
	{
		int y_min = (y1<y2)?y1:y2;
		int y_max = (y1<y2)?y2:y1;
		int y_temp = y_min;
		while(y_temp < y_max)
		{
			y_temp++;
			if(isBlocked(x1, y_temp))
				break;
		}
		if(y_max == y_temp)
			return 1;
		//两者直线之间有障碍，left、right为true表示该连线有障碍
		else
		{
			int x_temp1 = x1 - 1, x_temp2 = x1 + 1;
			bool left = false, right = false;
			while(1)
			{
				if(isBlocked(x_temp1,y_min))
					left = true;
				else if(isBlocked(x_temp1,y_max))
					left = true;
				if(isBlocked(x_temp2,y_min))
					right = true;
				else if(isBlocked(x_temp2,y_max))
					right = true;
				
				if(right == true || left == true)
					return 0;
				else
				{
					if(right == false)
					{
						y_temp = y_min;
						while(y_temp < y_max)
						{
							y_temp++;
							if(isBlocked(x_temp2,y_temp))
								break;
						}
						if(y_temp == y_max)
							return 1;
						x_temp2++;
					}
					if(left == false)
					{
						y_temp = y_min;
						while(y_temp < y_max)
						{
							y_temp++;
							if(isBlocked(x_temp1,y_temp))
								break;
						}
						if(y_temp == y_max)
							return 1;
						x_temp2--;
					}
				}
			}
		}
	}
	//同一行
	else if(y1 == y2)
	{
		int x_min = (x1<x2)?x1:x2;
		int x_max = (x1<x2)?x2:x1;
		int x_temp = x_min;
		while(x_temp < x_max)
		{
			x_temp++;
			if(isBlocked(x_temp,y1))
				break;
		}
		if(x_max == x_temp)
			return 1;
		//两者直线之间有障碍，left、right为true表示该连线有障碍
		else
		{
			int y_temp1 = y1 - 1, y_temp2 = y1 + 1;
			bool left = false, right = false;
			while(1)
			{
				if(isBlocked(x_min,y_temp1))
					left = true;
				else if(isBlocked(x_max,y_temp1))
					left = true;
				if(isBlocked(x_min,y_temp2))
					right = true;
				else if(isBlocked(x_max,y_temp2))
					right = true;
				
				if(right == true || left == true)
					return 0;
				else
				{
					if(right == false)
					{
						x_temp = x_min;
						while(x_temp < x_max)
						{
							x_temp++;
							if(isBlocked(x_temp,y_temp2))
								break;
						}
						if(x_temp == x_max)
							return 1;
						y_temp2++;
					}
					if(left == false)
					{
						x_temp = x_min;
						while(x_temp < x_max)
						{
							x_temp++;
							if(isBlocked(x_temp,y_temp1))
								break;
						}
						if(x_temp == x_max)
							return 1;
						y_temp2--;
					}
				}
			}
		}
	}
	//不在同行或同列
	else
	{
		int y_min = (y1<y2)?y1:y2;
		int y_max = (y1<y2)?y2:y1;
		int x_min = (x1<x2)?x1:x2;
		int x_max = (x1<x2)?x2:x1;
		int y_temp = y_min, x_temp = x_min;
		//转一次弯消除
		while(y_temp < y_max)
		{
			y_temp++;
			if(isBlocked(x_min, y_temp))
				break;
		}
		if(y_max == y_temp)
		{
			while(x_temp < x_max)
		    {
			    x_temp++;
			    if(isBlocked(x_temp, y_temp))
				    break;
		    }
		    if(y_max == y_temp)
			    return 1;
		}
		x_temp = x_min;
		y_temp = y_min;
		while(x_temp < x_max)
		{
			x_temp++;
			if(isBlocked(x_temp,y_min))
				break;
		}
		if(x_max == x_temp)
		{
			while(y_temp < y_max)
		    {
			    y_temp++;
			    if(isBlocked(x_temp, y_temp))
				    break;
		    }
		    if(x_max == x_temp)
			    return 1;
		}
		//一次转弯不能消除
		
	}
}