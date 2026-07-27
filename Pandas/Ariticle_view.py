import pandas as pd

def article_views(views: pd.DataFrame) -> pd.DataFrame:

    self_views = views[views['author_id'] == views['viewer_id']]
    
    result = self_views[['author_id']].drop_duplicates().rename(columns={'author_id': 'id'})
    result = result.sort_values(by='id', ascending=True)
    
    return result
    
