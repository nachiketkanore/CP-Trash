import requests

link = 'https://raw.githubusercontent.com/dwyl/quotes/master/quotes.json'
res = requests.get(link)
res = res.json()


for quote in res:
	print (quote['text'])

# print(type(res[0]))