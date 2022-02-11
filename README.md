# PA 01: The Art Gallery
London Kasper and Hazel Eroy
###Summary
For this program, we were tasked with finding the optimal set of paintings to place on an art gallery’s wall. Given a dataset with each painting’s price, width and other identifying information, we needed to find the best possible combination of paintings to represent the highest cumulative price on the wall while fitting the space constraints we were given. In order to do this, we developed three algorithms: a brute force algorithm, a most-expensive first algorithm, and a custom algorithm of our own design.
### Usage

###Building and Executing

###Brute Force Algorithm:
The brute force algorithm’s goal is to find the most profitable painting combination, regardless of computing time. It starts by finding all possible combinations of paintings that fit on a wall. As each combination is created, the total painting width is compared to the wall’s width. If the total painting width is shorter than the wall, then it is added into a vector of subset objects, otherwise it is discarded. Once the vector is filled, we use a totalPrice function to find the total price of the painting combinations. Once all those are found, there is logic to traverse through the vector to find the most expensive total price. This logic finds all possible subsets in a dataset and has to traverse a vector, this algorithm ultimately yields the worst results in regards to computation time but outputs the optimal total price.
As mentioned before, the brute force algorithm takes the longest to run due to its extensive process. We attempted to make this process less strenuous by adding an additional check to see if a subset would even be a viable wall option as it was created. Since brute force checks every single possible combination of paintings, it will eventually start creating subsets with sizes approaching that of the input data. While this may be a reasonable option for small data sets, as the size of the input data grows it becomes far less likely to be a possibility.
### Most-Expensive First Algorithm:
Our most-expensive first algorithm was meant to prioritize paintings by price alone. To do this, we sorted our vector of Painting objects by their prices, descending from most expensive at the front of our vector to least expensive at the end. From here, we started adding the most expensive paintings to a new vector until the sum of their widths was as large as it could be within the constraints of our dataset and the given width of the wall.

ADD MORE TO THIS, some graphs
###Custom Algorithm:
In order for our custom algorithm to be worth using, it needed to be more time-efficient than our brute force algorithm while producing a better output than the most-expensive first algorithm. To accomplish this, we added a new attribute to our Painting object, PriceByWidth, that stores each painting’s price to width ratio when a new Painting object is constructed. For example, if a painting takes up 10 units but is worth $1000, its PriceByWidth ratio is $10 per unit. However, if a painting only takes up 5 units and also costs $1000, its PriceByWidth ratio is $20 and is therefore a better display option. Using the same logic as the most-expensive algorithm, we sorted the full vector of painting options by their PriceByWidth ratio from greatest to least. We then iterated through the vector, adding paintings to the bestRatio vector until we no longer had space to add any more paintings from our dataset.
Our custom algorithm was very simple, but yielded great results. The total price of the paintings on the wall for this algorithm was consistently higher than that of the most-expensive first algorithm, and our custom algorithm often used up more space on the wall while producing significantly higher outputs. The structure of this algorithm allowed us to use the space we were given more efficiently. The results of our custom algorithm were comparable to that of the brute force algorithm, and the algorithm takes much less time to execute. Overall, we were very pleased with how our custom algorithm turned out.

ADD A BUNCH OF GRAPHS SHOWING ALL THREE ALGORITHMS TOGETHER

