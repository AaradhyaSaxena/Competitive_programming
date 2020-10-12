import numpy as np 
import pandas as pd 
import seaborn as sns 
import matplotlib.pyplot as plt  
from wordcloud import WordCloud 

from sklearn.feature_extraction.text import TfidfVectorizer, CountVectorizer 
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score, confusion_matrix
from nltk.corpus import stopwords
import gensim


train = pd.read_csv('dataset/train.csv')
test = pd.read_csv('dataset/test.csv')


train

X = train.expense_description
y = train.Category
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.25, random_state = 42, stratify=y)

y_train.value_counts()

####### 
from sklearn.naive_bayes import MultinomialNB
from sklearn.pipeline import Pipeline
from sklearn.feature_extraction.text import TfidfTransformer

nb = Pipeline([('vect', CountVectorizer()),
               ('tfidf', TfidfTransformer()),
               ('clf', MultinomialNB()),
              ])
nb.fit(X_train, y_train)
#########

my_categories = ['Daily Field Allowance', 'Travelling Expenses', 'Boarding', 'Lodging', 'Staff Welfare Expenses', 'Courier', 'Meal Allowances', 'Sales Promotion Expenses']


%%time
from sklearn.metrics import classification_report
y_pred = nb.predict(X_test)

print('accuracy %s' % accuracy_score(y_pred, y_test))
print(classification_report(y_test, y_pred,target_names=my_categories))
######################


from sklearn.linear_model import SGDClassifier

sgd = Pipeline([('vect', CountVectorizer()),
                ('tfidf', TfidfTransformer()),
                ('clf', SGDClassifier(loss='hinge', penalty='l2',alpha=1e-3, random_state=42, max_iter=5, tol=None)),
               ])
sgd.fit(X_train, y_train)

y_pred = sgd.predict(X_test)

print('accuracy %s' % accuracy_score(y_pred, y_test))
print(classification_report(y_test, y_pred,target_names=my_categories))
##################

from sklearn.linear_model import LogisticRegression

logreg = Pipeline([('vect', CountVectorizer()),
                ('tfidf', TfidfTransformer()),
                ('clf', LogisticRegression(n_jobs=-1, C=1e5)),
               ])
logreg.fit(X_train, y_train)

%%time
y_pred = logreg.predict(X_test)

print('accuracy %s' % accuracy_score(y_pred, y_test))
print(classification_report(y_test, y_pred,target_names=my_categories))

##############################
################################
############################
##############################

from tqdm import tqdm
tqdm.pandas(desc="progress-bar")
from gensim.models import Doc2Vec
from sklearn import utils
import gensim
from gensim.models.doc2vec import TaggedDocument
import re

def label_sentences(corpus, label_type):
    labeled = []
    for i, v in enumerate(corpus):
        label = label_type + '_' + str(i)
        labeled.append(gensim.models.doc2vec.TaggedDocument(v.split(), [label]))
    return labeled

X_train, X_test, y_train, y_test = train_test_split(train.expense_description, train.Category, random_state=0, test_size=0.25)
X_train = label_sentences(X_train, 'Train')
X_test = label_sentences(X_test, 'Test')
all_data = X_train + X_test

model_dbow = Doc2Vec(dm=0, vector_size=300, negative=5, min_count=1, alpha=0.065, min_alpha=0.065)
model_dbow.build_vocab([x for x in tqdm(all_data)])

%%time
for epoch in range(30):
    model_dbow.train(utils.shuffle([x for x in tqdm(all_data)]), total_examples=len(all_data), epochs=5)
    model_dbow.alpha -= 0.002
    model_dbow.min_alpha = model_dbow.alpha


def get_vectors(model, corpus_size, vectors_size, vectors_type):
    vectors = np.zeros((corpus_size, vectors_size))
    for i in range(0, corpus_size):
        prefix = vectors_type + '_' + str(i)
        vectors[i] = model.docvecs[prefix]
    return vectors

In [56]:

train_vectors_dbow = get_vectors(model_dbow, len(X_train), 300, 'Train')
test_vectors_dbow = get_vectors(model_dbow, len(X_test), 300, 'Test')

In [57]:

%%time
logreg = LogisticRegression(n_jobs=-1, C=1e5)
logreg.fit(train_vectors_dbow, y_train)

%%time
logreg = logreg.fit(train_vectors_dbow, y_train)
y_pred = logreg.predict(test_vectors_dbow)

print('accuracy %s' % accuracy_score(y_pred, y_test))
print(classification_report(y_test, y_pred,target_names=my_categories))
# Let’s train a Word2Vec model on our corpus.

tokenized_expense = train['expense_description'].apply(lambda x: x.split()) #tokenizing

model_w2v = gensim.models.Word2Vec(
            tokenized_expense,
            size=200, # desired no. of features/independent variables
            window=5, # context window size
            min_count=2,
            sg = 1, # 1 for skip-gram model
            hs = 0,
            negative = 10, # for negative sampling
            workers = 8, # no. of cores
            seed = 34)

model_w2v.train(tokenized_expense, total_examples= len(train['expense_description']), epochs = 20)

#############

# Importing the libraries 
import numpy as np 
import matplotlib.pyplot as plt 
import pandas as pd 
   
# Importing the dataset 
dataset = pd.read_csv('Churn_Modelling.csv') 
X = dataset.iloc[:, 3:13].values 
y = dataset.iloc[:, 13].values 
   
# Encoding categorical data 
from sklearn.preprocessing import LabelEncoder, OneHotEncoder 
labelencoder_X_1 = LabelEncoder() 
  
X[:, 1] = labelencoder_X_1.fit_transform(X[:, 1]) 
labelencoder_X_2 = LabelEncoder() 
  
X[:, 2] = labelencoder_X_2.fit_transform(X[:, 2]) 
onehotencoder = OneHotEncoder(categorical_features = [1]) 
  
X = onehotencoder.fit_transform(X).toarray() 
X = X[:, 1:] 
   
# Splitting the dataset into the Training set and Test set 
from sklearn.model_selection import train_test_split 
X_train, X_test, y_train, y_test = train_test_split( 
        X, y, test_size = 0.2, random_state = 0) 
  
# Fitting XGBoost to the training data 
import xgboost as xgb 
my_model = xgb.XGBClassifier() 
my_model.fit(X_train, y_train) 
   
# Predicting the Test set results 
y_pred = my_model.predict(X_test) 
   
# Making the Confusion Matrix 
from sklearn.metrics import confusion_matrix 
cm = confusion_matrix(y_test, y_pred) 

######


