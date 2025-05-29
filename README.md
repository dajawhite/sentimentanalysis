## Introduction
Have you ever read a tweet and thought, “Gee, what a positive outlook!” or “Wow, why so negative, friend?”  Can computers make the same determination?  They can surely try!

In Machine Learning, the task of assigning a **label** to a data item is called **classification** (putting things into different classes or categories).  The more specific name for what we’re going to do is sentiment analysis because you’re trying to determine the “sentiment” or attitude based on the words in a tweet.  The goal of the project is to build a sentiment classifier! Aren’t you excited??  ( ← That would be positive sentiment!)

You’ll be given a set of tweets called the **training data set** that are already pre-classified by humans as **positive** or **negative** based on their content.  You’ll analyze the frequency of occurrences of words in the tweets to develop a classification scheme.  Using your classification scheme, you’ll then classify another set of tweets called the **testing data set** and **predict** if each tweet has positive sentiment or negative sentiment.


## Building a Classifier
The goal in classification is to assign a class label to each element of a data set, positive or negative in our case.  Of course, we would want this done with the highest accuracy possible.  At a high level, the process to build a classifier (and many other machine learning models) has two major steps:

1. **Training Phase**
   - Input is a set of tweets with each tweet’s associated sentiment value.  This is the training data set.
   - Example: Assume you have 10 tweets and each is pre-classified with positive or negative sentiment.  How might you go about analyzing the words in these 10 tweets to find words more commonly associated with negative sentiment and words more commonly associated with positive sentiment?
   - The result of the training step will be one list of words that have an associated positive or negative sentiment with them depending on which type of tweet they appeared in more frequently.  Or, you might have 2 lists of words: one list is positive, one list is negative.

2. **Testing Phase**
   - In the testing phase, for a set of tweets called the testing data set, you predict the sentiment by using the list or lists of words extracted during the training phase.
   - Behind the scenes, you already know the sentiment of each of the tweets in the testing data set.  We’ll call this the actual sentiment or ground truth.  You then compare your predicted sentiment to the known sentiment for each of the testing tweets. Some of the predictions will be correct; some will be wrong.  The percentage correct is the accuracy, but more on this later.

## The Data
The data set we will be using in this project comes from real tweets posted around 11-12 years ago.  The original data was retrieved from Kaggle at https://www.kaggle.com/kazanova/sentiment140.  I’ve pre-processed it into the file format we are using for this project.  For more information, please see  Go, A., Bhayani, R. and Huang, L., 2009. Twitter sentiment classification using distant supervision. CS224N Project Report, Stanford, 1(2009), p.12.

**The preprocessed dataset can be accessed from is already included in the data folder in the project repo.**

## Input files
There will be 3 different input files:
* Training Data
* Testing Data Tweet (no sentiment column)
* Testing Ground Truth (id and sentiment for testing data for you to compare against).

The training data file is formatted as a comma-separated-values (CSV) file containing a list of tweets, each one on a separate line.  Each line of the data files include the following fields:
* Sentiment value (negative = 0, positive = 4, numbers in between are not used),
* the tweet id,
* the date the tweet was posted
* Query status (you can ignore this column)
* the twitter username that posted the tweet
* the text of the tweet itself

The testing data set is broken into two files:
* A CSV file containing formatted just like the training data EXCEPT no Sentiment column
* A CSV file containing tweet ID and sentiment for the testing dataset (so you can compare your predictions of sentiment to the actually sentiment ground truth)

Below are two example tweets from the training dataset:
```
4,1467811594,Mon Apr 06 22:20:03 PDT 2009,NO_QUERY,peruna_pony,"Beat TCU"
0,1467811595,Mon Apr 06 22:22:03 PDT 2009,NO_QUERY,the_frog,"Beat SMU"
```

Here is a tweet from the testing dataset:
```
1467811596,Mon Apr 06 22:20:03 PDT 2009,NO_QUERY,peruna_pony,"SMU > TCU"
```

The sentiment file for that testing tweet would be:
```
4, 1467811596
```

## Running your Program: Training and Testing

Your program should take 5 command line arguments:
1. training data set filename - the file with the training tweets
2. testing data set filename - tweets that your program will classify
3. testing data set sentiment filename - the file with the classifications for the testing tweet data
4. classifier results file name - see Output Files section below
5. classifier accuracy and errors file name - see Output Files section below

Example:
```
./classifier.out <train data> <test data> <test sentiment> <results> <accuracy/errors>
```

### Output Files
Your program should produce two output files. The first file should contain your classifier's
results for all tweets in the testing dataset in the same format as the sentiment file:
```
4, 1467811596
...
```

The second file should be organized as follows:
* The first line of the output file will contain the accuracy, a single floating point number with exactly 3 decimal places of precision.  See the section “How good is your classifier” below to understand Accuracy.
* The remaining lines of the file will contain for each tweet that your algorithm incorrectly classified your prediction,
the ground truth and the Tweet ID. This could be useful information as you tweak your algorithm to increase efficiency.

Example of the testing data tweet classifications file:
```
0.500
4, 1, 2323232323
1, 3, 1132553423
...
```
