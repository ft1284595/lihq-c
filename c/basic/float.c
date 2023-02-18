

int func(float f){
	if(f < 0)
		return -1;
	else if(f == 0)		//这里不能精确比较, 应该使用 if(fabs(f-0) <= 1e-6) 
			return 0;
		else
			return 0;
}
