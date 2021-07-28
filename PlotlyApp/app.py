# -*- coding: utf-8 -*-

# Run this app with `python app.py` and
# visit http://127.0.0.1:8050/ in your web browser.

import dash
import dash_core_components as dcc
import dash_html_components as html
import plotly.express as px
import pandas as pd

external_stylesheets = ['https://codepen.io/chriddyp/pen/bWLwgP.css']

app = dash.Dash(__name__, external_stylesheets=external_stylesheets)

# assume you have a "long-form" data frame
# see https://plotly.com/python/px-arguments/ for more options
df = pd.DataFrame({
    "Days": ["Monday", "Tuesday", "Wednesday"],
    "Amount": [15, 20, 25],
})

fig = px.bar(df, x="Days", y="Amount", color="Amount", barmode="group")

app.layout = html.Div(children=[
    html.H1(children='Push Counter Tracker'),

    html.Div(children='''
        Visualisation of number of pushups conducted each day.
    '''),

    dcc.Graph(
        id='example-graph',
        figure=fig
    )
])

if __name__ == '__main__':
    app.run_server(debug=True)
