



function readTextFile(file)
{
    let _return = "";
    let rawFile;

    if (window.XMLHttpRequest)
    {
        // code for IE7+, Firefox, Chrome, Opera, Safari
        rawFile = new XMLHttpRequest();
    }
    else
    {
        rawFile = new ActiveXObject("Microsoft.XMLHTTP");
    }

    rawFile.open("GET", file, false);
    rawFile.onreadystatechange = function ()
    {
        if(rawFile.readyState === 4)
        {
            if(rawFile.status === 200 || rawFile.status == 0)
            {
                let allText = rawFile.responseText;
                _return = allText;
            }
        }
    }
    rawFile.send(null);
    return _return;
}


function readJson(_jsonString)
{
    let _return = "";

    if (!_jsonString.length <= 0)
        let _return = JSON.parse(_jsonString);


    return _return;
}