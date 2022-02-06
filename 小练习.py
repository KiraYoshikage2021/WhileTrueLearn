#导入库
import requests
from bs4 import BeautifulSoup
#发送请求
website = 'http://books.toscrape.com/'
res = requests.get(website)
print(res.status_code)
html = res.text
soup = BeautifulSoup(html,'html.parser')
items = soup.find_all('ul',class_='nav nav-list')
for i in items:
    f1 = i.find('ul')
    f2 = f1.find_all('li')
    for j in f2:
        j = j.text
        j = j.strip()
        print(j)