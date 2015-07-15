public static String convert(String s){
	int intpart = Integer.parseInt(s.substring(0,s.indexOf('.')));

	double decpart = Double.parseDouble(s.substring('.'),s.length());
	string int_string = "";


	while(intpart>0){
		int r = intpart%2;
		intpart=intpart/2;
		int_string =  r+int_string;
	}

	Stringbuffer dec_string = new Stringbuffer();

	while(decpart>0){
		if(dec_string.length()>32) return "ERROR";
		if(decpart == 1){
			dec_string.append((int)decpart);
			break;
		}

		double r = decpart * 2;

		if(r > 1){
			dec_string.apppend(1);
			decpart=r-1;
		}
		else{
			dec_string.append(0);
			decpart=r;
		}
	}
	return int_string+"."+dec_string;
}