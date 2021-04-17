package cn.edu.xust.iot.mapper.pagehelper;

/**
 * 分页的大小枚举类
 *
 * @author huangxin
 */
public enum PageSize {

    SINGLE(1),

    /**
     * 最小的页面大小
     */
    SIZE_FIVE(5),

    SIZE_TEN(10),

    /**
     * 默认的页面大小
     */
    DEFAULT_PAGE_SIZE(15),
    SIZE_FIFTEEN(15),

    SIZE_TWENTY(20),

    SIZE_THIRTY(30),

    SIZE_FIFTY(50),

    SIZE_ONE_HUNDRED(100),

    ALL(-1);;

    private final int pageSize;

    PageSize(final int pageSize) {
        this.pageSize = pageSize;
    }

    public int getPageSize() {
        return pageSize;
    }

    /**
     * 根据传入的size返回一个PageSize对象
     * @param size
     * @return
     */
    public static PageSize getPageSize(int size){
        if(size<0){
            return ALL;
        }else if(size==5){
            return SIZE_FIVE;
        }else if(size==10){
            return SIZE_TEN;
        }else if(size==15){
            return DEFAULT_PAGE_SIZE;
        }else if(size==20){
            return SIZE_TWENTY;
        }else if(size==30){
            return SIZE_THIRTY;
        }else if(size==50){
            return SIZE_FIFTY;
        }else if(size==100){
            return SIZE_ONE_HUNDRED;
        }else{
            throw new IllegalArgumentException("非法分页大小参数，请检查分页大小参数是否传递合法");
        }
    }

}
