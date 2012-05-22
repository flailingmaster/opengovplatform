<?php

// Print out exported items.

 for($i=0;$i<count($themed_rows);$i++)
 {for($j=$i+1;$j<count($themed_rows);$j++)
  {if($themed_rows[$i][phpcode_1]<$themed_rows[$j][phpcode_1])
   {   
    $tmp=$themed_rows[$i];
    $themed_rows[$i]=$themed_rows[$j];
    $themed_rows[$j]=$tmp;
   }
  }
 }

 for($i=0;$i<count($themed_rows);$i++)
{
  $themed_rows[$i][rownumber]=$i+1;
}
$themed_rows=array_slice($themed_rows,0,10);
print '<tbody>';
foreach ($themed_rows as $count => $item_row):
  print '<tr><td>'.implode('<td>', $item_row) . '</tr>';
endforeach;

  ?>
