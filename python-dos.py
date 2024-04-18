import requests
f = input("website:")
def dos():

    a = requests.get(f)
    print(a.status_code)
while True:
    dos()
