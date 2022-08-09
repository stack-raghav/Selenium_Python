
#from selenium import webdriver
#from webdriver_manager.chrome import ChromeDriverManager


#driver = webdriver.Chrome(ChromeDriverManager().install())
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.firefox.options import Options
import time
import csv

with open("new_name.csv",encoding="utf8") as csv_file:
    data = list(csv.reader(csv_file))

options = Options()
options.headless = True 

for i in range(1150,2000):
    print(i)
    driver1 = webdriver.Firefox(executable_path='geckodriver.exe')
    driver2 = webdriver.Firefox(executable_path='geckodriver.exe')
    driver1.get("https://generator.email/")
    time.sleep(0.5)
    driver1.find_element_by_id('copbtn').click() 
    driver2.get("https://internshala.com/short-term-internships-bash?utm_source=refer_copylink&utm_medium=10400906")
    driver2.find_element_by_id('email').send_keys(Keys.CONTROL,'v')
    password = driver2.find_element_by_id('password')
    password.send_keys('a','v','R','@','1','b','z','7')
    firstname = driver2.find_element_by_id('first_name')
    firstname.send_keys("")
    firstname.send_keys(data[i][0]) 
    lastname = driver2.find_element_by_id('last_name')
    lastname.send_keys("")
    lastname.send_keys(data[i][1]) 
    driver2.find_element_by_xpath('/html/body/div[1]/div[17]/div[1]/div[2]/div[2]/div[2]/div/form/button').click()
    time.sleep(3)
    driver2.quit()
    time.sleep(0.5)
    #driver1.find_element_by_xpath('/html/body/div[3]/div/div/p/a[2]/button').click()
    time.sleep(5)
    link = driver1.find_elements_by_xpath('/html/body/div[4]/div/div/div/div[2]/div[2]/div[4]/div[3]/div/div[2]/div[1]/div[2]/a')
    if len(link) >0:
        link[0].click()
        """
        time.sleep(10)
        if len(link) <=0: 
            pass
        else:
            link[0].click()
    else:        
        link[0].click()
        """



