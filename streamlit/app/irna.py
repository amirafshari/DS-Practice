from bs4 import BeautifulSoup
import requests


def irna():
    url = 'https://en.irna.ir/tag/COVID-19'
    req = requests.get(url)
    soup = BeautifulSoup(req.content, 'lxml')

    titles = soup.find_all('h3')

    alist = []
    for link in titles:
        a = link.find_all('a')
        alist.append(a[0])


    titles = []
    for e in alist:
        titles.append((e.get_text(), e.get('href')))

    new_titles = [t for t in titles if 'COVID-19 kills' in t[0]]


    url = 'https://en.irna.ir' + new_titles[0][1]
    req = requests.get(url)
    soup = BeautifulSoup(req.content, 'lxml')

    p = soup.find('div', 'item-text')
    p = p.get_text().replace('.\n', ' ').split()


    numbers = []
    for s in p:
        try:
            numbers.append(int(s.replace(',', '')))
        except ValueError:
            pass

    death = numbers[0]
    case = numbers[3]
    return (death, case)