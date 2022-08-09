from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.firefox.options import Options
import time

driver = webdriver.Firefox(executable_path='geckodriver.exe')
driver.get("https://internshala.com/")
time.sleep(0.5)
driver.find_element_by_xpath('/html/body/div[1]/div[19]/div/nav/div[3]/ul/li[4]/button').click()
email = driver.find_element_by_id('modal_email')
email.send_keys("work.raghavgautam@gmail.com")
password = driver.find_element_by_id('modal_password')
password.send_keys("Rag@2000")
driver.find_element_by_id('modal_login_submit').click()
time.sleep(1)
driver.get('https://internshala.com/internships/software%20development-internship')
time.sleep(0.5)
driver.find_element_by_id("close_popup").click()
time.sleep(1)
for i in range(1,41):
    driver.find_element_by_xpath('/html/body/div[1]/div[22]/div[2]/div/div[3]/div[2]/div[2]/div/div[{}]/div[2]/a/div'.format(i)).click()
    #driver.find_element_by_css_selector('.btn-large').click()
print("Parent window title: " + driver.title)

#get current window handle
p = driver.current_window_handle

#get first child window
chwd = driver.window_handles

for w in chwd:
#switch focus to child window
    if(w!=p):
        driver.switch_to.window(w)
    break
time.sleep(0.9)
print("Child window title: " + driver.title)
'''
/html/body/div[1]/div[21]/div[2]/div/div[3]/div[2]/div[2]/div/div[1]/div[2]/a/div
/html/body/div[1]/div[21]/div[2]/div/div[3]/div[2]/div[2]/div/div[40]/div[2]/a/div
/html/body/div[1]/div[21]/div[2]/div/div[3]/div[2]/div[2]/div/div[40]/div[2]/a/div
/html/body/div[1]/div[21]/div[2]/div/div[3]/div[2]/div[2]/div/div[40]/div[2]/a/div
/html/body/div[1]/div[22]/div[2]/div/div[3]/div[2]/div[2]/div/div[40]/div[2]/a/div
/html/body/div[1]/div[22]/div[2]/div/div[3]/div[2]/div[2]/div/div[39]/div[2]/a/div

https://internshala.com/internships/software%20development-internship/page-1
'''