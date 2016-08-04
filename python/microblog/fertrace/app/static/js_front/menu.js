/**
 * Created by Ivan on 2015/7/27.
 */

$(function(){
    //¶¥²¿µ¼º½²Ëµ¥
    $('li.mainlevel').hover(
        function(){
            $(this).find('a:first').addClass("hover");
            var current_li=$(this);
            NavWaitSlide = setTimeout(function() {
                if(!$(current_li).children('ul').is(':visible'))
                {
                    $(current_li).find('ul').slideDown(200);
                }
            },100)
        },
        function(){
            clearTimeout(NavWaitSlide);
            $(this).find('ul').slideUp(100);
            $(this).find('a:first').removeClass("hover");
        }
    );
});
