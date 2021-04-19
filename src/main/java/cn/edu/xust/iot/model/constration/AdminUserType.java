package cn.edu.xust.iot.model.constration;

/**
 * 系统管理员类型
 * <ul>
 *     <li>Admin 系统管理员</li>
 *     <li>PM 项目经理</li>
 *     <li>CE 总工程师</li>
 *     <li>SO 安全员</li>
 *     <li>CW 施工员</li>
 *     <li>CC 造价员</li>
 * <ul/>
 *
 * @author HuangXin
 * @since 2021/4/19 21:32
 */
public enum AdminUserType {

    /**
     * Admin 系统超级管理员 具有对系统管理的最高权限
     */
    ADMIN("Admin"),
    /**
     * Project Manager(PM)  项目经理  权限和Admin权限一样<br/>
     * 项目经理是工地的负责人，工地的所有事，包括人、财、物的调配都管。
     * 负责组建精干、高效的项目管理班子，并确定项目经理部各类管理人员的职责权限；
     */
    PM("PM"),
    /**
     * Chief Engineer(CE)  总工程师 权限和Admin权限一样<br/>
     * 一般是工地的二把手，协助项目经理具体管理工程的事项，对项目的技术管理、质量管理、信息管理等负责，
     * 负责工程数量、质量的最终确认
     */
    CE("CE"),
    /**
     * Security officer(SO)  安全员  <br/>
     * 负责工人的施工安全的，给工人开会，教育等工作，如果干活过程中出现什么安全事故，
     * 工地的管理人员、相关利益方都要受到牵连，严重的话，还要负刑事责任
     */
    SO("SO"),
    /**
     * Construction Worker(CW) 施工员 只有对<b>工程进度管理</b>的权限<br/>
     * 负责落实项目经理、总工程师的各种指令。
     */
    CW("CW"),
    /**
     * Cost clerk(CC) 造价员  只有对<b>工程预算管理</b>的权限<br/>
     * 负责审查材料使用计划，做好成本审核;协助项目经理签署各类合同，向开发商申报该给多少钱
     */
    CC("CC");

    final String type;


    AdminUserType(final String type) {
        this.type = type;
    }

    public String getType() {
        return type;
    }
}
