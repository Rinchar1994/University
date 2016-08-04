/**
 * Created by Ivan on 2015/8/10.
 */
function setTabs(idfirst,id){
    var ptab=document.getElementById(id);
    var pul=ptab.getElementsByTagName("ul")[0];
    var pli=pul.getElementsByTagName("li");

    var id1=id.substring(0,id.length-4)
    var pnews=document.getElementById(id1);
    var pdiv=$(pnews).children("div");
    var divcc =document.getElementById(idfirst);

    for(var i=0;i<pli.length;i++){
        pli[i].suoyin=i;
        pli[i].onmouseover=function(){
            divcc.className = "news_title_change fl";
            for(var a=0;a<pli.length;a++){

                pli[a].className="";
                pdiv[a].className="hide";
            }
            this.className="news_tab_xx_on";
            $(this).children('a').addClass("news_tab_xx_on").parent().siblings().children('a').removeClass('news_tab_xx_on');
            pdiv[this.suoyin].className="";
        };

        pli[i].onmouseout=function()
        {
            divcc.className = "news_title1 fl";
        }

        if(i==0){
            pli[i].className="news_tab_xx_on";
            $(pli[i]).children('a').addClass("news_tab_xx_on").parent().siblings().children('a').removeClass('news_tab_xx_on');
            pdiv[i].className="";
        }
        else{
            pdiv[i].className="hide";
        }
    }





};


function setTabs2(idfirst,id){
    var ptab=document.getElementById(id);
    var pul=ptab.getElementsByTagName("ul")[0];
    var pli=pul.getElementsByTagName("li");

    var id1=id.substring(0,id.length-4)
    var pnews=document.getElementById(id1);
    var pdiv=$(pnews).children("div");
    var divcc =document.getElementById(idfirst);

    for(var i=0;i<pli.length;i++){
        pli[i].suoyin=i;
        pli[i].onmouseover=function(){
            divcc.className = "news_title_change";
            for(var a=0;a<pli.length;a++){

                pli[a].className="";
                pdiv[a].className="hide";
            }
            this.className="news_tab_xx_on";
            $(this).children('a').addClass("news_tab_xx_on").parent().siblings().children('a').removeClass('news_tab_xx_on');
            pdiv[this.suoyin].className="";
        };

        pli[i].onmouseout=function()
        {
            divcc.className = "news_title1 ";
        }

        if(i==0){
            pli[i].className="news_tab_xx_on";
            $(pli[i]).children('a').addClass("news_tab_xx_on").parent().siblings().children('a').removeClass('news_tab_xx_on');
            pdiv[i].className="";
        }
        else{
            pdiv[i].className="hide";
        }
    }





};