'''
Fill the stockhouse 
@Author: Rohith Uppala
'''

if __name__ == "__main__":
	w,b,p = map(int, raw_input().split())
	warehouse_dict = {}
	for ware_house in range(1, w+1):
		products = map(int, raw_input().split())
		for i in range(len(products)):
			product, cnt = i, products[i]
			if product not in warehouse_dict: 
				warehouse_dict[product] = {}
				warehouse_dict[product][ware_house] = cnt
			elif ware_house not in warehouse_dict[product]:
				warehouse_dict[product][ware_house] = cnt
			else:
				warehouse_dict[product][ware_house] += cnt
	for i in range(b):
		products = map(int, raw_input().split())
		result, flag = [], False
		for i in range(len(products)):
			product, cnt = i, products[i]
			warehouses = warehouse_dict.get(product, {})
			warehouses = sorted(warehouses.items(), key=lambda x: -x[1])
			temp = []			
			for warehouse in warehouses:
				if cnt > 0:
					if warehouse[0] not in temp:
						temp.append(warehouse[0])
					cnt = cnt - warehouse[1]	
				else: break
			if cnt > 0:
				flag = True
				break
			else:
				for t in temp:
					if t not in result: result.append(t)
		if flag == True:
			print "-1"
		else:
			print len(result)
