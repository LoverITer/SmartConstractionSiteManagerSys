package cn.edu.xust.iot.mapper.pagehelper;

import lombok.Data;

import java.util.Objects;

/**
 * 分页参数设置
 *
 * @author huangxin
 */
@Data
public class PageParam {

    /***分页页数*/
    private Integer page;

    /***分页大小*/
    private PageSize pageSize;

    public PageParam(int page, PageSize pageSize) {
        this.page = page;
        this.pageSize = pageSize;
    }

    public static PageParam create(int page, int pageSize) {
        return new PageParam(page, PageSize.getPageSize(pageSize));
    }


    public void setPageSize(PageSize pageSize) {
        if (Objects.isNull(pageSize)) {
            //默认每页的大小是15条数据
            this.pageSize = PageSize.DEFAULT_PAGE_SIZE;
        } else {
            this.pageSize = pageSize;
        }
    }


    public int getPageSize() {
        return this.pageSize.getPageSize();
    }
}
