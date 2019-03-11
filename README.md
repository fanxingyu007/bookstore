

Introduction 

With the development of the network, more and more shopping platforms appear in
front of us, and how to find high-quality and inexpensive items quickly becomes a problem that people need to face. The project we are working on is to help people find the books they need quickly and easily. In this project, our goal is to use our screening and integration to allow people to compare and select the books they need in a variety of online stores that are easy and fast. The entire project can be divided into three parts, the front-end UI of the project, the code implementation of the project, and the SQL statement to filter the data.
DATA

Figure 1. Flow Chart
Our flow chart is shown in Figure 1. First, we have selected data from three websites. The three sites are Amazon, Book Depository, and BAM (Book A Million).
 
We separately extracted 10,000 data from these three sites. The data type of each site includes the title, author, price, publication date, rating, and URL.
Figure 2. Date Set
Figure 2 shows the contents of some of our data. Then we combine these three data into one database and add IDs to all the data. ID is the key when we do data selection later. We then filter and integrate this database because there must be the same books on all three sites, but these books will have different prices, ratings, and publication dates. So we will choose the best book to integrate them into a new database. Figure 3 shows our new database. It is somewhat different from the database, and there are few categories, such as URLs. Then we perform SQL statement operations on this new database, classify them into different categories or classify them according to different requirements. This gave us the results we needed.
 
 Figure 3. New Data Set
The DATA Processing
First, we need to do data processing. For the original data that we catched from internet. As figure 4 shows there are so many types. And some of them can be used directly like book name and authors. While some of them can not be used directly like publish time and price. So, on our code, the first work is to deal with this problems. We capture the time and price. Then we divided it into different part. We choose the number that we need and change it from string type to float. Then these data can be used in our future work.

Also, we found that there are some information absent so that it would cause bug when we tried to make a new database. So the second work it use code to add mark to these absent information. For example, if the price is none, we add zero on them so that we can find which book has no price.
And when we deal with the data. Next work is find all books data which have the same book name and authors’ name. Because like the figure 5shows we found that there are so many books which are similar while the publish time and price are different. So we use c++ to process the data. We put all books with same name to a table and there is another table to save the books which have already appeared so that we have no same books appeared so many times. And the table save all books for the three bookstores.

Next work is choosing the best books from the same book table. And the way to choose the best book is by calculating the weight. Because these books’ price, rate and publish time are different. So, we calculate the weight of price, rate and time and then we get a total weight. And highest weight will be chosen to our final dataset.
Figuer 7. The code to calculate the weight
After putting the books data into a new database. Our integration work are finished. We reduce the number of books from 30000 to 25000. And the disappeared book are the books which have more than one version and have less weight.
UI Design
We first designed a simple UI to better show our data and the connection to the entire project. Figure 4 shows our UI, each button is connected to a different database, and our website address is user-friendly. Because the focus of this time is not on the design of the UI, we have not added too much functionality. We will further improve our UI in the future and integrate it with our database more perfectly. In order to design a perfect book selection system.
Also, there is some code that show how we design the UI. For more information, here is a link: https://media.oregonstate.edu/media/t/1_0nrna4ar shows our entire operation.

SQL

We use PhpMyadmin as our database. After, we get our final data, we import the
final data and original data into cs540_huanghen PhpMyadmin to search our results. Our main operation with structured query language can separate into four parts. 1. Update Data, 2. Separate Data, 3. Specify Data search, 4. Data connect.
5.1 Update Data
 UPDATE final SET final.category="Arts &
   Photography" WHERE final.category="All Art & Photography"

we find the category of the same type of book is different. Because the three different webs. So, we used this SQL to change these different category.
5.2 Separate Date
We have ten categories in our data. Therefore, we separated ten parts for each category, it can help users to find the highest feedback books in that category they want. And the result like the Figure 5.
 SELECT DISTINCT * FROM `final` WHERE final.category = "Ar
  ts & Photography" ORDER BY final.feedback DESC
 Figure 9. Arts & Photography books 5.3 Specify Data Search
Taking the top 100 most of expensive books as an example, we can find some specify data we want. In addition, we also can search by time and feedback. Figure 6 is our result with top 100 of most expensive books.
 SELECT * FROM `final
  ORDER BY final.price DESC LIMIT 0,100
 
Because we want users to get the details of the book after searching the book. We used the key value id to connect the original data and final data to show the web link for each book. In the beginning, we tried to use name as the key value, but we find there are some books have the same name. So, we add the ID that is not exist at the original data. Figure11 is the connected data.
Figure 11. the connected data 6. Conclusion
Through this project, we not only reviewed the contents of this semester, but also deepened the practical operation ability of the database. However, our project is still inadequate and needs to be improved. For example, how to better obtain data, make empty data disappear and so on. We hope that in the following study, we can further study the database knowledge, so that our professional competence can be improved better, so as to solve the problems that cannot be solved today.
 SELECT final.name, final.author,final.price,final.feedbac
  k,final.category,final.publishtime,final.id, datas.web FR
 OM final, datas WHERE final.id=datas.id ORDER BY final.pr
 ice DESC LIMIT 0,200
 
