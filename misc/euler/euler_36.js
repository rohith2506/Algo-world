function go(num,size) {
	var start = num+1;
	var numarray = [];
	while(start > 0){
		numarray.push(start%10);
		start = start/10;
	}
//	console.log(numarray.toString());
		





Maximum = 1000000;
var num = 1;
var size = 1;
var mainsum = 0;
while (num < Maximum){
	var numbers = go(num,size);
	num = num * 10;
	size = size + 1;
	for (var n = 0; n<numbers.length; n++){
		var temp = numbers[n];
		if (check(temp)){
			console.log(temp);
			mainsum = mainsum + temp;
		}
	}
}
console.log(mainsum);
