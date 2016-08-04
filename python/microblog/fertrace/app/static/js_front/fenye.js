/**
 * Created by zh on 2015/11/25.
 */




function fenye(totalRecords, pagenumber,recordsPerPage)
{

    this.totalRecords = totalRecords;
    this.pagenumber = pagenumber;
    this.recordsPerPage = recordsPerPage;
    var reArray = new Array();
    var totalPages = Math.ceil(totalRecords/recordsPerPage);

    var beginRecord = (pagenumber-1)*recordsPerPage+1;
    var endRecord = (pagenumber == totalPages)?totalRecords :(pagenumber*recordsPerPage);
    reArray[0] = totalPages;
    reArray[1] = beginRecord;
    reArray[2] = endRecord;

}

