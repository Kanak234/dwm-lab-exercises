#!/usr/bin/env python
# coding: utf-8

# In[ ]:


import pandas as pd


# In[ ]:


data=['kanak', 'john', 'jane', 'doe', 'smith', 'jones', 'brown', 'davis', 'miller', 'wilson']
df1 = pd.DataFrame(data, columns=['friends'])
df1.head()

