function textCounters(max,textarename,desc)
{	
    if (document.getElementById(textarename).value.length>parseInt(max)){
        document.getElementById(textarename).value=document.getElementById(textarename).value.substring(0,max)
    } else {
        var txtlength = document.getElementById(textarename).value.length;
        desc = desc?desc:'feedback-textarea-limit-count';
        $('#'+desc).html(parseInt(max)-txtlength) ;
    }
}

function textNoteCounters(max,textarename,desc)
{
    if($('#'+textarename).val().length > parseInt(max))
    {
        var text = $('#'+textarename).val().substr(0,max);
        $('#'+textarename).val(text);
    }
    else
    {
        var txtlength = $('#'+textarename).val().length;
        desc = desc?desc:'note-textarea-limit-count';
        $('#'+desc).html(parseInt(max)-txtlength) ;
    }
}

function resetTextNoteCounters(max,desc)
{
    desc = desc?desc:'note-textarea-limit-count';
    $('#'+desc).html(parseInt(max));
}
