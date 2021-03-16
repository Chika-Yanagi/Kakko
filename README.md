# Kakko
標準入力の文字列に対し、全ての括弧（（ と ）、｛ と ｝、［ と ］、＜ と ＞）が正しく入れ子になっているかを判定するプログラムを作成した。  
「正しく入れ子になっている」とは、開いていない括弧を閉じたり、開いた括弧を閉じなかったり、閉じていない括弧があるのに別の種類の括弧を閉じて  
しまったりすることがない、ということである。  

標準入力で与えられる文字列に対して全ての括弧が入れ子になっていればGoodを、正しくなければBadを標準出力に出力する。入力される文字列は512文字以下であると仮定する。  

入力例                                     　　　　　　 出力例  
{<apple>(and)([banana]and[mikan])}　　　　　　　　　　  Good  
    
app(le)[ an]d ba<nana((and m))ikan[]{}>               Good  
  
appl((e)((()))()) and [b[a[n[ana]]<>]{<>}]and mikan   Good  

apple(and)banana and>mikan                            Bad  
  
apple[and]banana<and mikan                            Bad  
  
apple(and<banana)and>mikan                            Bad  
