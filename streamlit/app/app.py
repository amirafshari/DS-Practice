import streamlit as st

import numpy as np
import pandas as pd

from bs4 import BeautifulSoup
import requests

import plotly.express as px

# crawling for daily cases and deaths
def newly_covid():
    url = 'https://www.worldometers.info/coronavirus'
    req = requests.get(url)
    soup = BeautifulSoup(req.content, 'lxml')

    soupp = soup.find_all('li', 'news_li')

    numbers = []
    for s in soupp:
        if 'Iran' in s.get_text().replace('\xa0[source]', ''):
            text = s.get_text().replace('\xa0[source]', '').split()
            for t in text:
                t = t.replace(',', '')
                try:
                    numbers.append(int(t))
                except ValueError:
                    pass

    numbers = (numbers[0], numbers[1])


    return numbers
new = newly_covid()

@st.cache
def daily_covid():
    url = 'https://covid19.who.int/WHO-COVID-19-global-data.csv'
    df = pd.read_csv(url)
    df.index = df.Date_reported
    df.drop(['Date_reported'], axis=1, inplace=True)
    iran = df[df['Country_code'] == 'IR']
    return iran
iran = daily_covid()

@st.cache
def dollar_history():
    url = 'https://api.accessban.com/v1/market/indicator/summary-table-data/price_dollar_rl'
    df = pd.read_json(url)
    df = df.data
    for e in df:
        del e[4:6]


    openn = []
    low = []
    high = []
    close = []
    date = []
    shamsi = []
    for e in df:
        openn.append(int(e[0].replace(',', '')))
        low.append(int(e[1].replace(',', '')))
        high.append(int(e[2].replace(',', '')))
        close.append(int(e[3].replace(',', '')))
        date.append(pd.to_datetime(e[4]))
        shamsi.append(e[5])

    df = pd.DataFrame(index=date)

    df['open'] = openn
    df['low'] = low
    df['high'] = high
    df['close'] = close
    df['shamsi'] = shamsi
    
    
    return df[::-1]

dollar_history = dollar_history()

def dollar_live():
    url = 'https://www.tgju.org/profile/price_dollar_rl'
    req = requests.get(url)
    soup = BeautifulSoup(req.content, 'lxml')
    soup = soup.find('span', {'data-col' : 'info.last_trade.PDrCotVal'})

    price = int(soup.get_text().replace(',', ''))

    return price



st.title(f'Today Cases: {new[0]}')
st.title('Daily Cases')
fig = px.bar(x=iran.index, y=iran['New_cases'])
fig


st.title(f'Today Deaths: {new[1]}')
st.title('Daily Deaths')
fig = px.bar(x=iran.index, y=iran['New_deaths'])
fig


st.title(f'Dollar: {dollar_live()}')
fig = px.line(dollar_history, x=dollar_history.index, y="close", title='Dollar Prices')
fig
